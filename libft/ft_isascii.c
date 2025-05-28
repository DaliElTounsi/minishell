/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:32 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/15 13:20:46 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*isascii() vérifie si c est un unsigned char sur 7 bits, 
entrant dans le jeu de caractères ASCII.*/
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
