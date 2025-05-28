/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:16:21 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/15 13:19:09 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Cette fonction permet de tester si un caractère est alphabétique ou non.
Un caractère sera considéré comme alphabétique s'il est de lettres minuscules 
ou de lettres majuscules. 
Rappel : les fonctions de cette librairie ne traitent que les caractères
purs ASCII. Les lettres accentuées ne seront donc pas considérées comme
des caractères alpha-numériques.*/
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
