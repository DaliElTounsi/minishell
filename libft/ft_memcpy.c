/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:53:54 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 19:06:34 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*sourc;
	size_t				i;

	if (!dest && !src && n > 0)
		return (NULL);
	dst = (unsigned char *)dest;
	sourc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = sourc[i];
		i++;
	}
	return (dest);
}
