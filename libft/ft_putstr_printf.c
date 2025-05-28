/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:58 by mohchams          #+#    #+#             */
/*   Updated: 2025/01/07 17:25:36 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_printf(char *s)
{
	int	len_str;

	if (!s)
	{
		ft_putstr_printf("(null)");
		return (6);
	}
	len_str = 0;
	while (*s)
	{
		ft_putchar_printf(*s);
		len_str++;
		s++;
	}
	return (len_str);
}
