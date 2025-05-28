/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:02:12 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 18:29:43 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Alloue (avec malloc(3)) et retourne une nouvelle
chaîne, résultat de la concaténation de s1 et s2.*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tail_s1_s2;
	char	*dest;

	tail_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((tail_s1_s2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, tail_s1_s2 + 1);
	return (dest);
}
