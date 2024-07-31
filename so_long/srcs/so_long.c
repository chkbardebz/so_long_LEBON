/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:19:42 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 15:49:01 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Leak quand le format de map est invalide
int	ft_strchr_x_base(char **map, char obj_cherche)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == obj_cherche)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strchr_y_base(char **map, char obj_cherche)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == obj_cherche)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	launch_prog(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->img_char = mlx_xpm_file_to_image(vars->mlx, "sprites/character.xpm",
			&vars->width, &vars->height);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm",
			&vars->width, &vars->height);
	vars->img_ground = mlx_xpm_file_to_image(vars->mlx, "sprites/ground.xpm",
			&vars->width, &vars->height);
	vars->img_coin = mlx_xpm_file_to_image(vars->mlx, "sprites/collectible.xpm",
			&vars->width, &vars->height);
	vars->img_exit = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm",
			&vars->width, &vars->height);
	vars->img_char_exit = mlx_xpm_file_to_image(vars->mlx,
			"sprites/char_on_exit.xpm", &vars->width, &vars->height);
	if (ft_verif_img(vars) > 0)
		ft_exit_img(vars);
	vars->win = mlx_new_window(vars->mlx, vars->win_xsize, vars->win_ysize,
			"so_long");
	mlx_hook(vars->win, 2, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, 17, 0, ft_exit, vars);
	put_walls(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_char, vars->x1,
		vars->y1);
	mlx_loop(vars->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (write(2, "Error\nUn seul argument est demande\n", 36));
	if (verif_filename(argv[1]) >= 1)
		return (write(2, "Error\nNom du fichier invalide\n", 30));
	len_init(argv[1], &vars);
	if (ft_check(&vars) >= 1)
		return (1);
	vars_init(&vars);
	if (ft_verif(&vars) >= 1)
	{
		ft_free_map(&vars, vars.map);
		return (1);
	}
	ft_verif_interior_map(&vars);
	ft_printf("\n\nLA MAP PASSE !!!!\n\n");
	ft_printf("nombre de lignes : %d\nnombre de colonnes : %d\n", vars.lastline,
		vars.lenline);
	launch_prog(&vars);
	return (0);
}
