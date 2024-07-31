/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_interior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:19:05 by judenis           #+#    #+#             */
/*   Updated: 2024/04/09 12:25:29 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_memset(void *str, int value, size_t len)
{
	unsigned char	*str_temp;

	str_temp = (unsigned char *)str;
	while (len > 0)
	{
		*(str_temp++) = (unsigned char)value;
		len--;
	}
	return (str);
}

int	verif_interior(t_vars *vars, int **visited, int y, int x)
{
	if (vars->map[y][x] == '1' || visited[y][x] == 1 || vars->lastline <= y
		|| y < 0 || vars->lenline <= x || x < 0)
		return (0);
	if (vars->map[y][x] == 'C')
		vars->c_verif_interior++;
	if (vars->map[y][x] == 'E')
		vars->e_verif_interior++;
	visited[y][x] = 1;
	verif_interior(vars, visited, y - 1, x);
	verif_interior(vars, visited, y + 1, x);
	verif_interior(vars, visited, y, x - 1);
	verif_interior(vars, visited, y, x + 1);
	return (1);
}

void	ft_verif_interior_map(t_vars *vars)
{
	int	i;
	int	**visited_c;

	i = 0;
	vars->c_verif_interior = 0;
	visited_c = (int **)malloc(vars->lastline * sizeof(int *));
	while (i < vars->lastline)
	{
		visited_c[i] = malloc((vars->lenline + 1) * sizeof(int));
		ft_memset(visited_c[i], 0, (vars->lenline + 1) * sizeof(int));
		i++;
	}
	vars->e_verif_interior = 0;
	verif_interior(vars, visited_c, ft_strchr_y(vars, 'P'), ft_strchr_x(vars,
			'P') - 1);
	ft_free_map_int(vars, visited_c);
	if (vars->c_verif_interior != vars->max_coin || vars->e_verif_interior != 1)
	{
		ft_printf("Chemin impossible !");
		ft_free_map(vars, vars->map);
		exit(1);
	}
}
