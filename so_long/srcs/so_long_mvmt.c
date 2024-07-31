/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mvmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:24:18 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 12:41:29 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Fonction pour gérer le déplacement vers le haut (W)
int	move_up(t_vars *vars)
{
	if (vars->y1 <= 0 || vars->map[(vars->y1 - 32) / 32][vars->x1 / 32] == '1')
		return (1);
	vars->y1 -= 32;
	vars->mvmt++;
	return (0);
}

// Fonction pour gérer le déplacement vers la gauche (A)
int	move_left(t_vars *vars)
{
	if (vars->x1 <= 0 || vars->map[(vars->y1) / 32][(vars->x1 - 32)
		/ 32] == '1')
		return (1);
	vars->x1 -= 32;
	vars->mvmt++;
	return (0);
}

// Fonction pour gérer le déplacement vers le bas (S)
int	move_down(t_vars *vars)
{
	if (vars->y1 + 32 >= vars->win_ysize || vars->map[(vars->y1 + 32)
			/ 32][vars->x1 / 32] == '1')
		return (1);
	vars->y1 += 32;
	vars->mvmt++;
	return (0);
}

// Fonction pour gérer le déplacement vers la droite (D)
int	move_right(t_vars *vars)
{
	if (vars->x1 + 32 >= vars->win_xsize || vars->map[(vars->y1) / 32][(vars->x1
			+ 32) / 32] == '1')
		return (1);
	vars->x1 += 32;
	vars->mvmt++;
	return (0);
}
