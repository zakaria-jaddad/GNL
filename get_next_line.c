/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:45:02 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/07 11:08:15 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	check_new_line(char *s)
{
	int	i;
	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *result)
{
	int	n_bytes;
	int	i;
	char	*content;

	content = NULL;
	if (result && check_new_line(result))
		return (result);
	while (1)
	{
		content = (char *) malloc(BUFFER_SIZE + 1);
		if (content == NULL)
			break ;
		if ((n_bytes = read(fd, content, BUFFER_SIZE)) <= 0)
			break ;
		result = ft_strjoin(result, content);
		free(content);
		if (result == NULL || check_new_line(result))
			break ;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char *content;
	static char	*rest;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = read_line(fd, rest);
	if (content == NULL)
		return (NULL);
	if ((i = check_new_line(content)))
	{
		rest = ft_strdup(content + i + 1);
		content = ft_substr(content, 0, i + 1);
		return (content);
	}
	rest = NULL;
	return (content);
}

int main(void) {
	int fd = open("file.txt", O_RDONLY, 0);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
	}
	return EXIT_SUCCESS;
}

