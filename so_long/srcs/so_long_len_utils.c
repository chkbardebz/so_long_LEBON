/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_len_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:44:55 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 15:48:12 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_lastline(char *filename)
{
	int		i;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide\n", 31);
		exit(1);
	}
	compteur = 1;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n')
			compteur++;
		i++;
	}
	close(fd);
	return (compteur);
}

int	ft_lenline(char *filename)
{
	int		i;
	char	buffer[4096];
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n')
		{
			close(fd);
			return (i);
		}
		i++;
	}
	close(fd);
	return (i);
}
