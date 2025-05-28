/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:00 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 19:13:28 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ces fonctions vérifient si le caractère c, qui doit avoir la valeur 
d'un unsigned char ou valoir EOF, rentre dans une catégorie donnée, en accord 
avec la localisation en cours.*/
#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}
