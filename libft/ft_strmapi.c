/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:31:33 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 18:27:10 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applique la fonction ’f’ à chaque caractère de
la chaîne de caractères ’s’, passant son index
comme premier argument et le caractère lui-même
comme second argument. Une nouvelle chaîne de
caractères est créée (avec malloc(3)), résultant
des applications successives de ’f’.*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*tab;

	i = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (0);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
