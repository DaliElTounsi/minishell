/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:27:00 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 18:44:12 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La fonction memset() remplit les n premiers 
octets de la zone mémoire pointée par s avec l'octet c*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}

/*int main(int av, char **av)
{
    if (ac != 2)
        return (0);
    size_t i;
    
    i = 0;
    wihle(av[1][i])
    {
        ft_memset(av[1], av[1][i], ft_atoi(av[3]));
        i++;
    }
}*/