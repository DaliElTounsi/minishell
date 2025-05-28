/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:47 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/15 13:22:30 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ces fonctions vérifient si le caractère c,
 qui doit avoir la valeur d'un unsigned char ou valoir EOF,
  entre dans une catégorie donnée d'après les paramètres*/
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
