/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:45 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/09 20:27:37 by mohchams         ###   ########.fr       */
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
	while (!ft_isspace(input[*i + len]) && !ft_strchr("|><", input[*i + len]))
		len++;
	return (len);
}

void	add_token_back(t_token **head, t_token *new)
{
	t_token	*current;

	if (!head || !new)
		return ;
	current = *head;
	if (!*head)
		*head = new;
	else
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
		new->next = NULL;
	}
}

void	add_word_token(t_token **head, char *input, int *i)
{
	t_token	*token;
	int		len;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return ;
	len = get_token_length(input, i);
	token->type = TOKEN_WORD;
	token->value = ft_substr((input + *i), 0, len);
	printf("la valeur du token_word : %s\n", token->value);
	if (!token->value)
	{
		free(token);
		return ;
	}
	*i += len;
	token->next = NULL;
	if (!*head)
		*head = token;
	else
		add_token_back(head, token);
}

void	add_operator_token(t_token **head, int handle_return,
		char *input, int *i)
{
	t_token	*token;
	int		len;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return ;
	len = 0;
	if (handle_return >= 1 && handle_return <= 3)
		len = 1;
	else if (handle_return == 4 || handle_return == 5)
		len = 2;
	if (handle_return == 1)
		token->type = TOKEN_PIPE;
	else if (handle_return == 2)
		token->type = TOKEN_REDIR_IN;
	else if (handle_return == 3)
		token->type = TOKEN_REDIR_OUT;
	else if (handle_return == 4)
		token->type = TOKEN_APPEND;
	else if (handle_return == 5)
		token->type = TOKEN_HEREDOC;
	token->value = ft_substr((input + *i), 0, len);
	if (!token->value)
	{
		free(token);
		return ;
	}
	token->next = NULL;
	if (!*head)
		*head = token;
	else
		add_token_back(head, token);
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
	 
	head = NULL;
	
	if (!input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
			i++;
		handle_return = handle_operator(input, &i);		
		if (handle_return == -1)
			break ;
		if (handle_return > 0)
		{
			add_operator_token(&head, handle_return, input, &i);
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


