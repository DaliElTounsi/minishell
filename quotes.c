/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:30:24 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/18 16:13:41 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	serch_quotes(char *input, int *i, int count_quotes)
{
	int serch;

	serch = 0;
	while (input[*i + serch])
	{
		if (ft_strchr("\'", input[*i + serch]))
			return (check_simple_quotes(input, i));
		else if (ft_strchr("\"", input[*i + serch]))
			return (check_double_quotes(input, i));
		serch++;
	}
	return (0);
}
int	check_simple_quotes(char *input, int *i)
{
	int count_quotes;
	int	len;

	len = 0;
	count_quotes = 0;
	while (input[*i + len])
	{	
		if (ft_strchr("\'", input[*i + len]))
		{
			printf("je compte les simple quotes\n");
			count_quotes++;
		}
		len++;
	}
	printf("nombre de simple quotes = %d\n", count_quotes);
	return (count_quotes);
}

int	check_double_quotes(char *input, int *i)
{
	int count_quotes;
	int	len;

	len = 0;
	count_quotes = 0;
	while (input[*i + len])
	{	
		if (ft_strchr("\"", input[*i + len]))
		{
			printf("je compte les doubles quotes\n");
			count_quotes++;
		}
		len++;
	}
	printf("nombre de doubles quotes = %d\n", count_quotes);
	return (count_quotes);
}

int len_quoets(char *input, int *i, char quotes)
{
    int start_i;
    int len;

    start_i = i;
    len = 0;    

    while (input[*i + len] != quotes && input[*i + len])
        len++;
    if (!input[*i + len])
        return (NULL);
    return (len); 
}