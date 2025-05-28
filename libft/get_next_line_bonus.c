/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchams <mohchams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:15:38 by mohchams          #+#    #+#             */
/*   Updated: 2024/12/23 19:31:30 by mohchams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*nouv_stat(char *stat)
{
	char	*nouvelle_stat;
	size_t	len_ligne;
	size_t	reste_len;

	if (!stat)
		return (NULL);
	len_ligne = 0;
	while (stat[len_ligne] && stat[len_ligne] != '\n')
		len_ligne++;
	if (!stat[len_ligne] || !stat[len_ligne + 1])
	{
		free(stat);
		return (NULL);
	}
	reste_len = ft_strlen(stat + len_ligne + (stat[len_ligne] == '\n'));
	nouvelle_stat = malloc(reste_len + 1);
	if (!nouvelle_stat)
	{
		free(stat);
		return (NULL);
	}
	ft_strlcpy(nouvelle_stat, stat + len_ligne
		+ (stat[len_ligne] == '\n'), reste_len + 1);
	free(stat);
	return (nouvelle_stat);
}

char	*extract_line(char *stat_temp)
{
	char	*line;
	size_t	len;

	if (!stat_temp)
		return (NULL);
	len = 0;
	while (stat_temp[len] && stat_temp[len] != '\n')
		len++;
	line = malloc(len + (stat_temp[len] == '\n') + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stat_temp, len + 1 + (stat_temp[len] == '\n'));
	return (line);
}

static char	*gere_stat_temp(char *stat, char *buffer)
{
	char	*stat_temp;

	if (!buffer)
		return (NULL);
	if (!stat)
	{
		stat_temp = malloc(ft_strlen(buffer) + 1);
		if (stat_temp)
			ft_strlcpy(stat_temp, buffer, ft_strlen(buffer) + 1);
		else
			return (NULL);
	}
	else
	{
		stat_temp = ft_strjoin(stat, buffer);
		if (stat_temp)
			free(stat);
		else
			return (free(stat), NULL);
	}
	return (stat_temp);
}

char	*stat_temporaire(int fd, char *stat)
{
	char	*buffer;
	int		oct_lut;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	oct_lut = read(fd, buffer, BUFFER_SIZE);
	if (oct_lut == -1)
		return (free(buffer), NULL);
	while (oct_lut > 0)
	{
		buffer[oct_lut] = '\0';
		stat = gere_stat_temp(stat, buffer);
		if (!stat || ft_strchr(stat, '\n'))
			break ;
		oct_lut = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (oct_lut == 0 && (!stat || *stat == '\0'))
	{
		free(stat);
		return (NULL);
	}
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat[FD_MAX];
	char		*line;
	char		*stat_temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (free(stat[fd]), stat[fd] = NULL, NULL);
	stat_temp = stat_temporaire(fd, stat[fd]);
	if (!stat_temp || *stat_temp == '\0')
		return (free(stat[fd]), stat[fd] = NULL, NULL);
	line = extract_line(stat_temp);
	if (!line || *line == '\0')
		return (free(stat_temp), NULL);
	stat[fd] = nouv_stat(stat_temp);
	return (line);
}
/*#include <fcntl.h>

int main()
{
    int     fd1, fd2;
    char    *line1, *line2;

    fd1 = open("salut_test1.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("Erreur d'ouverture fichier 1");
        return (1);
    }
    fd2 = open("salut_test2.txt", O_RDONLY);
    if (fd2 < 0)
    {
        perror("Erreur d'ouverture fichier 2");
        close(fd1);
        return (1);
    }
    while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
{
    if (line1)
    {
        printf("Fichier 1 : %s", line1);
        free(line1);
    }
    if (line2)
    {
        printf("Fichier 2 : %s", line2);
        free(line2);
    }
}

    close(fd1);
    close(fd2);
    return (0);
}*/