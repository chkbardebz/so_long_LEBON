/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:46:35 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 12:41:23 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_empty_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	return (0);
}

// Fonction pour vérifier si la ligne dépasse les limites
int	check_first_line(char *line, t_vars *vars)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if ((line[i] != '1' && line[i] != '\n' && line[i] != '\0')
			|| ft_strlen(line) - 1 != (size_t)vars->lenline)
			return (1);
		i++;
	}
	return (0);
}

int	check_last_line(char *line, t_vars *vars)
{
	int		i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if ((line[i] != '1' && line[i] != '\n' && line[i] != '\0')
			|| ft_strlen(line) != (size_t)vars->lenline)
			return (1);
		i++;
	}
	return (0);
}

// Fonction pour vérifier les lignes internes
int	check_inner_line(char *line, t_vars *vars)
{
	size_t	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if ((line[i] != 'E' && line[i] != 'C' && line[i] != '1'
				&& line[i] != '0' && line[i] != 'P' && line[i] != '\n'
				&& line[i] != '\0')
			|| ft_strlen(line) - 1 != (size_t)vars->lenline)
			return (1);
		i++;
	}
	return (0);
}

int	check_line(char *line, int compteur, t_vars *vars)
{
	if (compteur == 0)
	{
		if (check_first_line(line, vars))
			return (1);
	}
	if (compteur == vars->lastline - 1)
	{
		if (check_last_line(line, vars))
			return (1);
	}
	if (compteur > 0 && compteur < vars->lastline - 1)
	{
		if (check_inner_line(line, vars))
			return (1);
	}
	return (0);
}
