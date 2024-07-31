/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:20:37 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 12:40:58 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Fonction pour allouer dynamiquement le tableau de lignes
char	**allocate_table(t_vars *vars, int lastline, int lenline)
{
	int		i;
	char	**tab;
	int		error;

	i = 0;
	error = 0;
	tab = (char **)malloc(sizeof(char *) * (lastline));
	if (!tab)
		free(tab);
	while (i < lastline)
	{
		tab[i] = (char *)malloc(sizeof(char) * (lenline + 1));
		if (!tab[i])
			error = 1;
		i++;
	}
	if (error == 1)
		ft_free_map(vars, tab);
	return (tab);
}

void	read_file_data(int fd, char **tab, int lastline)
{
	char	*buffer;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	buffer = (char *)malloc(sizeof(char) * 4069);
	while (i < lastline)
	{
		j = 0;
		while (read(fd, buffer + k, 1) == 1)
		{
			if (buffer[k] == '\n' || buffer[k] == '\0')
				break ;
			tab[i][j] = buffer[k];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	free(buffer);
}

char	**convert(t_vars *vars)
{
	char	**tab;
	int		fd;

	fd = open(vars->filename, O_RDONLY);
	tab = allocate_table(vars, vars->lastline, vars->lenline);
	if (!tab)
		ft_free_map(vars, vars->map);
	read_file_data(fd, tab, vars->lastline);
	close(fd);
	return (tab);
}
