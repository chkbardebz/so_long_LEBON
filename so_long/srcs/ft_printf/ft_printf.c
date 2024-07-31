/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:41:41 by judenis           #+#    #+#             */
/*   Updated: 2024/04/09 12:11:54 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_printf(const char *format, ...)
{
	va_list	field;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(field, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'
				|| format[i + 1] == 'p' || format[i + 1] == 'd' || format[i + 1]
				== 'i' || format[i + 1] == 'u' || format[i + 1] == 'x'
				|| format[i + 1] == 'X' || format[i + 1] == '%'))
		{
			print_len += cas_par_cas(format, i, field);
			i = i + 2;
		}
		else
		{
			print_len += ft_character(format[i]);
			i++;
		}
	}
	va_end(field);
	return (print_len);
}

int	cas_par_cas(const char *format, int i, va_list field)
{
	int	print_len;

	print_len = 0;
	if (format[i + 1] == 'c')
		print_len += ft_character((int)va_arg(field, int));
	else if (format[i + 1] == 's')
		print_len += ft_string((char *)va_arg(field, char *));
	else if (format[i + 1] == 'p')
		print_len += ft_pointer((unsigned long long)va_arg(field,
					unsigned long long));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		print_len += ft_decimal((int)va_arg(field, int));
	else if (format[i + 1] == 'u')
		print_len += ft_unsigned_decimal((unsigned int)va_arg(field,
					unsigned int));
	else if (format[i + 1] == 'x')
		print_len += ft_tolower_hexadecimal((unsigned int)va_arg(field,
					unsigned int));
	else if (format[i + 1] == 'X')
		print_len += ft_toupper_hexadecimal((unsigned int)va_arg(field,
					unsigned int));
	else if (format[i + 1] == '%')
		print_len += write(1, &format[i], 1);
	return (print_len);
}
