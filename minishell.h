/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:32:04 by mohchams          #+#    #+#             */
/*   Updated: 2025/06/09 18:54:35 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

typedef enum	e_token_type
{
	TOKEN_WORD,      /* Commande ou argument */
	TOKEN_PIPE,      /* | */
	TOKEN_REDIR_IN,  /* < */
	TOKEN_REDIR_OUT, /* > */
	TOKEN_APPEND,    /* >> */
	TOKEN_HEREDOC,   /* << */
	TOKEN_QUOTE,     /* ' ou " (à ajouter plus tard) */
	TOKEN_VAR/* $VAR ou $? (à ajouter plus tard) */
}	t_token_type;

typedef struct	s_token
{
	char			*value;/* Valeur du token (ex. "ls", "|") */
	t_token_type	type;/* Type du token */
	struct s_token	*next; /* Pointeur vers le token suivant */
}	t_token;

t_token	*split_tokens(char *input);
int		handle_operator(char *input, int *i);
void	add_word_token(t_token **head, char *input, int *i);
void	add_token_back(t_token **head, t_token *new);
void	add_operator_token(t_token **head, int handle_return, char *input, int *i);
int		get_token_length(char *input, int *i);

#endif