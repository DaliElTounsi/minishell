/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:45 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/18 15:36:06 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	get_token_length(char *input, int *i)
{
	int	len;

	len = 0;

	while (!ft_isspace(input[*i + len]) && !ft_strchr("|><\'\"", input[*i + len]))
		len++;
	return (len);
}

int	handle_operator(char *input, int *i)
{
	if (operator(input[*i]))
	{
		if (input[*i] == '|')
		{
			if (operator(input[*i + 1])) 
				return (-1);
			else
			{
				ft_printf("Opérateur PIPE trouvé\n"); 
				(*i)++;
				return (TOKEN_PIPE);
			}
		}
		if (input[*i] == '<')
		{
			if (!operator(input[*i + 1]))
			{
				ft_printf(("Opérateur REDIR_IN trouvé\n"), (*i)++); 
				return (TOKEN_REDIR_IN);
			}
			else if (input[*i + 1] == '<' && operator(input[*i + 2]))
				return (-1);
			else if (input[*i + 1] == '<' && !operator(input[*i + 2]))
			{
				(ft_printf("Opérateur  HEREDOC trouvé\n"), (*i)++, (*i)++);
				return (TOKEN_HEREDOC);
			}
		}
		if (input[*i] == '>')
		{
			if (!operator(input[*i + 1]))
			{
				ft_printf("Opérateur REDIR_OUT trouvé\n"), (*i)++;
				return (TOKEN_REDIR_OUT);
			}
			else if (input[*i + 1] == '>' && operator(input[*i + 2]))
				return (-1);
			else if (input[*i + 1] == '>' && !operator(input[*i + 2]))
			{
				(ft_printf("Opérateur  APPEND trouvé\n"), (*i)++, (*i)++);
				return (TOKEN_APPEND);
			}
		}
	}
	return (0);
}

t_token	*split_tokens(char *input)
{
	int i;
	t_token *head;
	int	handle_return;
	int start_i;
	int serch_quotes;
	 
	head = NULL;
	serch_quotes = 0;
	
	if (!input)
		return (NULL);
	i = 0;
	if (serch_quotes < 0)
		return (NULL);
	while (input[i])
	{
		if (ft_isspace(input[i]))
			i++;
		start_i = i;
		handle_return = handle_operator(input, &i);		
		if (handle_return == -1)
			break ;
		if (handle_return > 0)
		{
			add_operator_token(&head, handle_return, input, &start_i);
			continue ;
		}
		if (handle_return == 0)
		{
			add_word_token(&head, input, &i);
			i++;
		}
		else
			i++;
	}
	return (head);
}


