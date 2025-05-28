/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:15:55 by mohchams          #+#    #+#             */
/*   Updated: 2025/01/07 17:39:37 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned long long n)
{
	int	len_nbr;

	len_nbr = 0;
	if (n >= 10)
		len_nbr += ft_putnbr_unsigned(n / 10);
	ft_putchar_printf((n % 10) + '0');
	len_nbr++;
	return (len_nbr);
}
