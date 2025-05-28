/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:24:10 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/18 15:34:12 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*copie n octets depuis la zone mémoire src vers la zone mémoire dest.
 Les deux zones peuvent se chevaucher */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src && n > 0)
		return (NULL);
	if ((unsigned char *)dest > (const unsigned char *)src)
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return ((unsigned char *)dest);
}

/*int	main()
{
	char src[] = "bonjour";
	char *dest = src + 1;
	size_t n = 5;
	
	printf("avant foncton src = %s, dest = %s, n = %zu\n",src, dest, n);
	ft_memmove(dest, src, n);
	printf("apres foncton src = %s, dest = %s, n = %zu\n",src, dest, n);
	return (0);
}*/
