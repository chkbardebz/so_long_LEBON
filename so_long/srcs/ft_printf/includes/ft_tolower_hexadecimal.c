/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:47 by judenis           #+#    #+#             */
/*   Updated: 2024/04/09 12:11:36 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	ft_hex(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_hex(nb / 16);
		ft_hex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'));
		else
			ft_putchar((nb - 10 + 'a'));
	}
}

int	ft_tolower_hexadecimal(unsigned int nb)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_hex(nb);
	return (ft_hex_len(nb));
}
