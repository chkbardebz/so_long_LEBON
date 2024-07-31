/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 03:56:38 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 13:35:19 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	len_init(char *filename, t_vars *vars)
{
	vars->filename = filename;
	vars->lastline = ft_lastline(vars->filename);
	vars->lenline = ft_lenline(vars->filename);
	vars->compteur = 0;
}

int	ft_check(t_vars *vars)
{
	int		fd;
	char	*line;
	int		error;

	error = 0;
	fd = open(vars->filename, O_RDONLY);
	while (vars->compteur < vars->lastline)
	{
		line = get_next_line(fd);
		if (check_line(line, vars->compteur, vars) || line[0] == '\n')
			error = 1;
		free(line);
		line = NULL;
		vars->compteur++;
	}
	free(line);
	close(fd);
	if (error == 1)
		return (write(2, "Error\nMap Error\n", 17));
	return (0);
}

int	ft_verif(t_vars *vars)
{
	char	p;
	char	c;
	char	e;

	p = 'P';
	c = 'C';
	e = 'E';
	if (ft_strrchr_verif(vars, p) != 1)
		return (write(2, "Error\nUn seul point d'apparition est demande\n",
				46));
	if (ft_strrchr_verif(vars, c) < 1)
		return (write(2, "Error\nPas assez de collectible\n", 32));
	if (ft_strrchr_verif(vars, e) != 1)
		return (write(2, "Error\nUne seule sortie est demandee\n", 37));
	return (0);
}

int	ft_verif_img(t_vars *vars)
{
	if (!vars->img_char || !vars->img_wall || !vars->img_ground
		|| !vars->img_exit || !vars->img_coin || !vars->img_char_exit)
		return (write(2, "Error\nImage.s invalide.s\n", 26));
	return (0);
}

int	verif_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'r' || filename[i - 2] != 'e' || filename[i
			- 3] != 'b' || filename[i - 4] != '.')
		return (1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_len	len;
// 	t_vars	vars;

// 	if (argc > 2 || argc < 2)
// 		return (write(2, "Error\n", 6));
// 	len_init(argv[1] ,&len);
// 	if (ft_check(&len) == 6)
// 		return (1);
// 	vars_init(&vars, &len);
// 	if (ft_verif(vars.map) == 6)
// 		return (1);
// 	printf("\n\nCA PASSE !!!!\n\n");
// 	launch_prog(&vars);
// 	free(vars.map);
// 	vars.map = NULL;
// }
