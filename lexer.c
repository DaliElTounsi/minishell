/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:45 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/02 18:21:19 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_length(char *input, int *i)
{
	int		len;
	
	len = 0;
	while (input[*i + len] != ' ' && input[*i + len] != '\t' && input[*i + len] != '|' &&
			input[*i + len] != '>' && input[*i + len] != '<' && input[*i + len])
			len++;		
	printf("Longueur du mot: %d\n", len);
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
	
	len = get_word_length(input, i);
	token->type = TOKEN_WORD;
	token->value = ft_substr((input + *i), 0, len);
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
			return (1);	
		}
		else if (c == '>' || c == '<')
		{	
			while (input[*i + 1] == ' ')
				(*i)++;
			if (!input[*i + 1])
			{
				(ft_printf("Erreur : redirection à la fin\n"), (*i)++);
				return(-1);
			}
			else if (c == '<')
				ft_printf(("Opérateur REDIR_IN trouvé\n"), (*i)++); 
			else if (c == '>')
				ft_printf("Opérateur REDIR_OUT trouvé\n"), (*i)++;
			return (1);
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
			return (4);
		}
		else if (c == '<')
		{
			(ft_printf("Opérateur  HEREDOC trouvé\n"), (*i)++, (*i)++);
			return (5);
		}
		else
			return (-1);
	}
	else if (input[*i] == c && input[*i + 1] != c)
	{
		while (input[*i + 1] == ' ')
			(*i)++;
		if (!input[*i + 1])
		{
			(ft_printf("Erreur : pipe à la fin\n"), (*i)++);
			return(-1);
		}
		if (c == '>')
		{
    		(ft_printf("Opérateur REDIR_OUT trouvé\n"), (*i)++);
			return (3);
		}
		else if (c == '<')
		{
			(ft_printf("Opérateur REDIR_IN trouvé\n"), (*i)++);
			return (2);
		}
		else if (c == '|')
		{
			ft_printf("Opérateur PIPE trouvé\n"); 
			(*i)++;
			
			return (1);
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

t_token *split_tokens(char *input)
{
	int i;
	int	j;
	int	is_first_token;
	t_token *head;
	int	handle_return;
	char	ops[4];
	 
	head = NULL;
	ops[0] = '|';
	ops[1] = '>';
	ops[2] = '<';
	ops[3] = '\0';
	
	if (!input)
		return (NULL);
	i = 0;
	is_first_token = 1;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else
		{
			j = 0;
			handle_return = 0;
			while (j < 3)
			{
				handle_return = handle_operator(input, &i, is_first_token, ops[j]);	
				if (handle_return > 0 || handle_return == -1)
					break ;
				j++;
			}
		}
		if (handle_return > 0)
                continue;
		if (handle_return == -1)
                break;

		if (input[i] != ' ' && input[i] != '\t')
		{
			add_word_token(&head, input, &i);
			printf("Ajouté mot à i=%d\n", i);
			is_first_token = 0;
		}
	}
	return (NULL);
}


