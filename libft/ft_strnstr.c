/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:45:08 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 18:26:23 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*str1;
	char	*to_find;
	size_t	i;
	size_t	j;

	i = 0;
	str1 = (char *)s1;
	to_find = (char *)s2;
	if (to_find[0] == '\0')
		return (str1);
	while (str1[i] && i < len)
	{
		j = 0;
		while (str1[i + j] == to_find[j] && (i + j) < len)
		{
			j++;
			if (to_find[j] == '\0')
				return (str1 + i);
		}
		i++;
	}
	return (NULL);
}
/*int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("%s ", ft_strnstr(av[1], av[2], ft_atoi(av[3])));
}*/
