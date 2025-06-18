/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:39:45 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/18 15:40:14 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token *head)
{
	t_token	*temp;
	t_token	*temp2;

	temp = head;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2->value);
		free(temp2);
	}
}

int	main(int ac, char **av)
{
	char *input;
	t_token	*l;
	(void)ac;
	(void)av;
	while (1)
	{
		input = readline("minishell> ");
		if (!input || ft_strncmp("exit", input, 5) == 0)
		{
			printf("exit\n");
			free(input);
			exit(0);
		}
		add_history(input);
		l = split_tokens(input);
		free(input);
		free_token(l);
	}
}
