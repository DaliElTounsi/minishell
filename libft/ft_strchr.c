/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:23:39 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 18:31:14 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*str;

	str = (const unsigned char *)s;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
int main(int ac, char **av)
{
        //ft_putstr(ft_strchr(av[1], av[2][0]));
		printf("%p\n\n", ft_strchr(av[1], '\0'));
		printf("%p", strchr(av[1], '\0'));
    return (0);   
}*/
