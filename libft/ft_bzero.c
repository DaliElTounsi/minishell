/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:56:03 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/18 14:08:47 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La  fonction bzero() met à 0 les n premiers octets du bloc pointé par s
       (octets contenant « \0 »).*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
