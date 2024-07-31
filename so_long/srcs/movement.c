/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:05:49 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 13:10:31 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static size_t	ft_digitlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	i;
	size_t	n_len;
	char	*str;

	nbr = (long)n;
	n_len = ft_digitlen(nbr);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n == 0)
		str[i] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[(n_len - 1) - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[n_len] = 0;
	return (str);
}

void	ft_keycode_verif(int keycode, t_vars *vars)
{
	if (keycode == 119)
		move_up(vars);
	if (keycode == 97)
		move_left(vars);
	if (keycode == 115)
		move_down(vars);
	if (keycode == 100)
		move_right(vars);
	if (keycode == 65307)
		ft_exit(vars);
}

void	ft_fin(t_vars *vars)
{
	ft_printf("\nBravo ! Fini en %d mouvements\n\n", vars->mvmt);
	ft_exit(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	ft_keycode_verif(keycode, vars);
	vars->nb = ft_itoa(vars->mvmt);
	if (vars->map[vars->y1 / 32][vars->x1 / 32] == 'C')
	{
		vars->coin++;
		vars->map[vars->y1 / 32][vars->x1 / 32] = '0';
	}
	if (vars->map[vars->y1 / 32][vars->x1 / 32] == 'E'
		&& vars->coin == vars->max_coin)
		ft_fin(vars);
	put_walls(vars);
	if (vars->map[vars->y1 / 32][vars->x1 / 32] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_char_exit,
			vars->x1, vars->y1);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_char, vars->x1,
			vars->y1);
	mlx_string_put(vars->mlx, vars->win, 5, 10, 0xffffff, vars->nb);
	ft_printf("nbr de mouvements : %d\n", vars->mvmt);
	free(vars->nb);
	vars->nb = NULL;
	return (0);
}
