/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:36:59 by mohchams          #+#    #+#             */
/*   Updated: 2025/01/08 12:50:11 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(int n)
{
	long int	nb;
	int			len_str;

	nb = n;
	len_str = 0;
	if (nb < 0)
	{
		ft_putchar_printf('-');
		len_str++;
		nb = -nb;
	}
	if (nb > 9)
		len_str += ft_putnbr_printf(nb / 10);
	ft_putchar_printf(nb % 10 + 48);
	len_str++;
	return (len_str);
}
