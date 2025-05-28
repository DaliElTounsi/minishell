/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:08:37 by mohchams          #+#    #+#             */
/*   Updated: 2025/01/08 13:26:44 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert_str(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	if (c == 'x')
		return (ft_putnbr_hexa_printf
			(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_hexa_printf
			(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_printf(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putptr_printf(va_arg(args, void *)));
	if (c == '%')
		return (ft_percent_printf());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len_str;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	len_str = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len_str += convert_str(str[i], args);
		}
		else
		{
			ft_putchar_printf(str[i]);
			len_str++;
		}
		i++;
	}
	va_end(args);
	return (len_str);
}
