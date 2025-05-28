/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:16:01 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 19:08:08 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*renvoie un entier négatif, nul ou positif
 si les n premiers octets de s1
 sont respectivement inférieurs, égaux ou supérieurs 
 aux n premiers octets de s2*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*str1;
	const unsigned char		*str2;
	size_t					i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
