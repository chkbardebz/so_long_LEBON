/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:43:28 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 15:15:23 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit(t_vars *vars)
{
	vars->mvmt = 0;
	vars->x1 = 0;
	vars->y1 = 0;
	vars->width = 0;
	vars->height = 0;
	vars->max_coin = 0;
	vars->coin = 0;
	if (vars->nb)
		free(vars->nb);
	mlx_destroy_image(vars->mlx, vars->img_char);
	mlx_destroy_image(vars->mlx, vars->img_wall);
	mlx_destroy_image(vars->mlx, vars->img_ground);
	mlx_destroy_image(vars->mlx, vars->img_coin);
	mlx_destroy_image(vars->mlx, vars->img_exit);
	mlx_destroy_image(vars->mlx, vars->img_char_exit);
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win_xsize = 0;
	vars->win_ysize = 0;
	mlx_destroy_display(vars->mlx);
	if (vars->map != NULL)
		ft_free_map(vars, vars->map);
	free(vars->mlx);
	exit(0);
}

int	ft_exit_img(t_vars *vars)
{
	vars->mvmt = 0;
	vars->x1 = 0;
	vars->y1 = 0;
	vars->width = 0;
	vars->height = 0;
	vars->max_coin = 0;
	vars->coin = 0;
	if (vars->img_char != NULL)
		mlx_destroy_image(vars->mlx, vars->img_char);
	if (vars->img_wall != NULL)
		mlx_destroy_image(vars->mlx, vars->img_wall);
	if (vars->img_ground != NULL)
		mlx_destroy_image(vars->mlx, vars->img_ground);
	if (vars->img_coin != NULL)
		mlx_destroy_image(vars->mlx, vars->img_coin);
	if (vars->img_exit != NULL)
		mlx_destroy_image(vars->mlx, vars->img_exit);
	if (vars->img_char_exit != NULL)
		mlx_destroy_image(vars->mlx, vars->img_char_exit);
	if (vars->map != NULL)
		ft_free_map(vars, vars->map);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	ft_free_map_int(t_vars *vars, int **map)
{
	int	i;

	i = 0;
	while (i < vars->lastline)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (0);
}

int	ft_free_map(t_vars *vars, char **map)
{
	int	i;

	i = 0;
	while (i < vars->lastline)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (0);
}
