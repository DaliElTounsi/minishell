/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:53:22 by mohchams          #+#    #+#             */
/*   Updated: 2025/01/08 13:04:31 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_printf(void *ptr)
{
	unsigned long long	addr;
	int					len_ptr;

	if (!ptr)
	{
		ft_putstr_printf("(nil)");
		return (5);
	}
	addr = (unsigned long long)ptr;
	ft_putstr_printf("0x");
	len_ptr = 2;
	len_ptr += ft_putnbr_hexa_printf(addr, "0123456789abcdef");
	return (len_ptr);
}
