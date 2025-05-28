#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"

int	main(int ac, char **av)
{
	// char *input;
	if (ac == 2)
	{
	 	split_tokens(av[1]);
		return (0);
	}
}

	// while (1)
		// {
		// 	input = readline("minishell> ");
		// 	if (!input)
		// 	{
		// 		printf("exit\n");
		// 		break;
		// 	}
		// 	add_history(input);
		// 	printf("%s\n", input);
		// 	free(input);
		// }