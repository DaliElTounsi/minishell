/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:44:12 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 19:11:38 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*malloc_null(void)
{
	char	*res;

	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int nb)
{
	int		len;
	long	nbr;
	char	*str_nb;

	len = len_nb(nb);
	nbr = nb;
	if (nb == 0)
		return (malloc_null());
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	str_nb = malloc((len + 1) * sizeof(char));
	if (!str_nb)
		return (NULL);
	str_nb[len] = '\0';
	while (len--)
	{
		str_nb[len] = ((nbr % 10) + 48);
		nbr = nbr / 10;
	}
	if (nb < 0)
		str_nb[0] = '-';
	return (str_nb);
}
/*int	main(int ac, char **av)
{
	char	*nbr;
	
	if (ac != 2)
		return (0);
	nbr = ft_itoa(ft_atoi(av[1]));
	ft_putstr_fd(nbr, 1);
	return (0);
}*/