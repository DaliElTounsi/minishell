/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:45 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/07 19:21:29 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}
int	get_token_length(char *input, int *i)
{
	int		len;
	
	len = 0;
	while (ft_isspace(input[*i + len]) && !"|><"[*i + len])
		len++;	
	// while (ft_isspace(input[*i + len]) && input[*i + len] != '|' &&
	// 		input[*i + len] != '>' && input[*i + len] != '<' && input[*i + len])
	// 		len++;		
	// printf("Longueur du mot: %d\n", len);
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
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return ;
	int len;
	
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

void add_operator_token(t_token **head, int handle_return, char *input, int *i)
{
	t_token	*token;
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return ;
	int len;
	
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
	printf("la valeur du token_operator : %d\n", token->type);
	// printf("%c\n", input[*i]);

	if (handle_return >= TOKEN_APPEND)
		*i = *i + 1;
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

int handle_operator(char *input, int *i, int is_first_token, char c)
{

	if (input[*i] == c && is_first_token)
	{
		(ft_printf("syntax error near unexpected token %c\n", c), i++);
		return (-1);
	}
	else if (input[*i] == c && (!input[*i + 1] || input[*i + 1] == ' '))
	{
		if (c == '|')
		{
			while (input[*i + 1] == ' ')
				(*i)++;
			if (!input[*i + 1])
			{
				(ft_printf("Erreur : pipe à la fin\n"), (*i)++);
				return(-1);
			}
			else
			{
				ft_printf("Opérateur PIPE trouvé\n"); 
				(*i)++;
			}
			return (TOKEN_PIPE);	
		}
		if (c == '>' || c == '<')
		{	
			while (input[*i + 1] == ' ')
				(*i)++;
			if (!input[*i + 1])
			{
				(ft_printf("Erreur : redirection à la fin\n"), (*i)++);
				return(-1);
			}
			if (c == '<')
			{
				ft_printf(("Opérateur REDIR_IN trouvé\n"), (*i)++); 
				return (TOKEN_REDIR_IN);
			}
			if (c == '>')
			{
				ft_printf("Opérateur REDIR_OUT trouvé\n"), (*i)++;
				return (TOKEN_REDIR_OUT);
			}
			return (-1);
		}
	}
	else if (input[*i] == c && input[*i + 1] == c)
	{
		if (c == '|')
		{
			(ft_printf("Erreur : opérateur PIPE double\n"), (*i)++, (*i)++);
			return (-1);
		}
		else if ((c == '>' || c == '<') && (input[*i + 2] == '>' || input[*i + 2] == '<'))
		{
			(ft_printf("syntax error near unexpected token '>'\n"), (*i)++, (*i)++);
			return (-1);
		}
		else if (c == '>')
		{
			while (input[*i + 1] == ' ')
				(*i)++;
			if (!input[*i + 1])
			{
				(ft_printf("syntax error near unexpected token '>>'\n"), (*i)++);
				return(-1);
			}
			else
				(ft_printf("Opérateur APPEND trouvé\n"), (*i)++, (*i)++);
			return (TOKEN_APPEND);
		}
		else if (c == '<')
		{
			while (input[*i + 1] == ' ')
				(*i)++;
			(ft_printf("Opérateur  HEREDOC trouvé\n"), (*i)++, (*i)++);
			return (TOKEN_HEREDOC);
		}
		else
			return (-1);
	}
	// else if (input[*i] == c && input[*i + 1] != c)
	// {
	// 	while (input[*i + 1] == ' ')
	// 		(*i)++;
	// 	if (!input[*i + 1])
	// 	{
	// 		(ft_printf("Erreur : pipe à la fin\n"), (*i)++);
	// 		return(-1);
	// 	}
	// 	if (c == '>')
	// 	{
    // 		(ft_printf("Opérateur REDIR_OUT trouvé\n"), (*i)++);
	// 		return (TOKEN_REDIR_OUT);
	// 	}
	// 	else if (c == '<')
	// 	{
	// 		(ft_printf("Opérateur REDIR_IN trouvé\n"), (*i)++);
	// 		return (TOKEN_REDIR_IN);
	// 	}
	// 	else if (c == '|')
	// 	{
	// 		ft_printf("Opérateur PIPE trouvé\n"); 
	// 		(*i)++;
			
	// 		return (TOKEN_PIPE);
	// 	}
	// 	else
	// 		return (-1);
	// 	i++;
	// }
	return (0);
}

t_token *split_tokens(char *input)
{
	int i;
	int	j;
	int	is_first_token;
	t_token *head;
	int	handle_return;
	 
	head = NULL;
	
	if (!input)
		return (NULL);
	i = 0;
	is_first_token = 1;
	while (input[i])
	{
		if (ft_isspace(input[i]))
			i++;
		else
		{
			j = 0;
			handle_return = 0;
			while (j < 3)
			{
				handle_return = handle_operator(input, &i, is_first_token, "|><"[j]);	
				if (handle_return > 0 || handle_return == -1)
					break ;
				j++;
			}
		}
		if (handle_return > 0)
		{
			add_operator_token(&head, handle_return, input, &i);
			printf("je suis passe par la\n");
			continue ;
		}
		if (handle_return == -1)
                break;

		if (!ft_isspace(input[i]) && !operator(input[i]))
		{
			add_word_token(&head, input, &i);
			is_first_token = 0;
		}
	}
	return (head);
}


