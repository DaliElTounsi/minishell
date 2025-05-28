/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:34:53 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 18:30:12 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères transmise comme argument,
et en passant son index comme premier argument.
Chaque caractère est transmis par adresse à ’f’
afin d’être modifié si nécessaire*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
