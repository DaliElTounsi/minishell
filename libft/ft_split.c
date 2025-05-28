/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:06:22 by mohchams          #+#    #+#             */
/*   Updated: 2024/11/19 19:50:40 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cont_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	cont_len(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ftt_strdup(char const *s, char c, size_t i)
{
	char	*copy;
	size_t	j;
	size_t	len;

	len = cont_len(s, c, i);
	j = 0;
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (s[i] && s[i] != c)
		copy[j++] = s[i++];
	copy[j] = '\0';
	return (copy);
}

static char	**free_ligne(char **tab, size_t i)
{
	while (tab[i] && i + 1 > 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	tab = malloc((cont_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (j++, s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		tab[j] = ftt_strdup(s, c, i);
		if (!tab[j])
			return (free_ligne(tab, j - 1));
		i += cont_len(s, c, i);
	}
	tab[j] = NULL;
	return (tab);
}
/*int	main(int ac, char **av)
{
	char	**split;
	size_t	i;

	if (ac != 3)
		return (0);
	split = ft_split(av[1], av[2][0]);
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		printf("Taille du mot : %zu : ", cont_len(split[i], av[1][0], 0));
		ft_putstr_fd(split[i], 1);
		ft_putchar_fd('\n', 1);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}*/
