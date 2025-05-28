/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:37:10 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/18 13:59:44 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* examine les n premiers octets de la zone mémoire pointée
 par s à la recherche de la première occurrence de c */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

/*int main(int ac, char **av)
{
    ft_putstr(ft_memchr(av[1], av[2][0], ft_atoi(av[3])));
    return (0);   
}*/