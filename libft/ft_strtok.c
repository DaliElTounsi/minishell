/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:00:41 by mohchams          #+#    #+#             */
/*   Updated: 2025/04/08 15:06:31 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*token;

	next_token = NULL;
	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);
	token = next_token;
	while (*next_token)
	{
		if (ft_strchr(delim, *next_token))
		{
			*next_token = '\0';
			next_token++;
			return (token);
		}
		next_token++;
	}
	next_token = NULL;
	return (token);
}
