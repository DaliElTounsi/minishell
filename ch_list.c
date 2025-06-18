/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:34:06 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/18 16:17:27 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_word_token(t_token **head, char *input, int *i)
{
	t_token	*token;
	int		len;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return ;
	len = get_token_length(input, i);
	if (len < 0)
	{
		printf("erreur de quotes\n");
		return ;
	}
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
	token->type = handle_return;
	// printf("Index *i=%d, caractère='%c'\n", *i, input[*i]);
	// printf("Index *i=%d, caractère='%c'\n", *i + 1, input[*i + 1]);
	token->value = ft_substr((input + *i), 0, len);
	printf("la valeur du token %s\n", token->value);
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