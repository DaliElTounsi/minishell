/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:57 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/15 13:42:30 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*vérifie s'il s'agit d'un caractère imprimable, y compris l'espace*/
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
