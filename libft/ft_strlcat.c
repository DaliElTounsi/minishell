/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:11:26 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/15 10:43:37 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	long_src;
	size_t	long_dst;
	size_t	i;
	size_t	j;

	long_dst = ft_strlen(dst);
	long_src = ft_strlen(src);
	if (siz <= long_dst)
		return (long_src + siz);
	i = 0;
	j = long_dst;
	while (src[i] && j < (siz - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (long_dst + long_src);
}
