/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:04:43 by mohchams          #+#    #+#             */
/*   Updated: 2025/03/15 15:19:32 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La fonction strdup() renvoie un pointeur sur
 une nouvelle chaîne de caractères qui
 est dupliquée depuis s. La mémoire occupée par
  cette nouvelle chaîne est obtenue en appelant malloc(3), 
 et peut (doit) donc être libérée avec free(3).
 La fonction strndup() est identique, mais ne copie au plus que n octets.*/
#include "libft.h"

static void	*ft_strcpy(char *src, char *copy)
{
	int	i;

	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	size_t	siz;

	siz = ft_strlen(src);
	copy = malloc((siz + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strcpy(src, copy);
	return (copy);
}
