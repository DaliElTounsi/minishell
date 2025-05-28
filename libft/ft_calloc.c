/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:10:55 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 14:33:57 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La fonction calloc() alloue la mémoire nécessaire pour un tableau
de nmemb éléments de size octets, et renvoie un pointeur vers la mémoire 
allouée. Cette zone est remplie avec des zéros. 
Si nmemb ou si size est nulle, calloc renvoie soit NULL ou un unique pointeur
qui pourra être passé ultérieurement à free() avec succès. */
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, 0, num * size));
}
