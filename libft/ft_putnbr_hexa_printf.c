/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:27:27 by mohchams          #+#    #+#             */
/*   Updated: 2025/02/06 14:42:03 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_base(char *base)
{
	char	tab[257];
	int		i;

	i = 0;
	while (i < 257)
		tab[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || tab[(unsigned char)base[i]])
			return (0);
		tab[(unsigned char)base[i]] = 1;
		i++;
	}
	if (i <= 2)
		return (0);
	return (i);
}

int	ft_putnbr_hexa_printf(unsigned long long nb, char *base )
{
	int			len_base;
	int			len_str;

	len_base = check_base(base);
	if (!len_base)
		return (0);
	len_str = 0;
	if (nb >= (unsigned long long)len_base)
		len_str += ft_putnbr_hexa_printf(nb / len_base, base);
	ft_putchar_printf(base[nb % len_base]);
	len_str++;
	return (len_str);
}
