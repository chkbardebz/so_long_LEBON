/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:27:24 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 15:48:31 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strchr_x(t_vars *vars, char searched_obj)
{
	int		i;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	fd = open(vars->filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide\n", 31);
		exit(1);
	}
	compteur = 0;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			compteur = 0;
		if (buffer[i] == searched_obj)
			return (compteur);
		i++;
		compteur++;
	}
	close(fd);
	return (compteur);
}

int	ft_strchr_y(t_vars *vars, char searched_obj)
{
	int		i;
	int		j;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	j = 0;
	fd = open(vars->filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide\n", 31);
		exit(1);
	}
	compteur = 0;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			j++;
		if (buffer[i] == searched_obj)
			return (j);
		i++;
	}
	close(fd);
	return (compteur);
}

int	ft_strrchr_verif(t_vars *vars, char searched_obj)
{
	int		i;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	fd = open(vars->filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide\n", 31);
		exit(1);
	}
	compteur = 0;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == searched_obj)
			compteur++;
		i++;
	}
	close(fd);
	return (compteur);
}

void	put_walls(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->lastline)
	{
		j = 0;
		while (j < vars->lenline)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall, j
					* 32, i * 32);
			if (vars->map[i][j] == '0' || vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ground,
					j * 32, i * 32);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_coin, j
					* 32, i * 32);
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_exit, j
					* 32, i * 32);
			j++;
		}
		i++;
	}
}

void	vars_init(t_vars *vars)
{
	vars->nb = NULL;
	vars->win_xsize = vars->lenline * 32;
	vars->win_ysize = vars->lastline * 32;
	vars->map = convert(vars);
	vars->x1 = (ft_strchr_x(vars, 'P') - 1) * 32;
	vars->y1 = ft_strchr_y(vars, 'P') * 32;
	vars->mvmt = 0;
	vars->max_coin = ft_strrchr_verif(vars, 'C');
	vars->coin = 0;
}
