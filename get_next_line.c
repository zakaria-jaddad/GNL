/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:45:02 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/09 12:32:57 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>


int get_new_line_index(char *s)
{
	int	i;
	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')	
			return (i);
	}
	return (0);
}


char *read_line(int fd, char *result)
{
	char	*buffer;
	char	*content = ft_strdup(result);
	int n_bytes;
	if (content && get_new_line_index(content))
		return (content);
	while (1)
	{
		buffer = (char *) ft_calloc(sizeof(char), (size_t) (BUFFER_SIZE + 1));
		if (buffer == NULL)
		{
			free(content);
			return (NULL);
		}
		if ((n_bytes = read(fd, buffer, BUFFER_SIZE)) <= 0) // 0 if read nothing -1 if EOF
		{
			free(buffer);
			return (NULL);
		}
		content = ft_strjoin(content, buffer);
		free(buffer);
		if (content == NULL || get_new_line_index(content))
			break ;
	}
	return (content);
}

char *get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, rest);
	if (buffer == NULL)
		return (NULL);
	// here is the limbo;
	i = get_new_line_index(buffer);
	rest = buffer + i;
	line = ft_substr(buffer, 0, i);
	free(buffer);
	return (line);	
}

/* int main(int argc, char *argv[]) */
/* { */
/* 	int fd = open("file.txt", O_RDONLY, 0); */
/* 	char *line; */
/* 	while ((line = get_next_line(fd))) */
/* 	{ */
/* 		printf("%s", line); */
/* 		free(line); */
/* 	} */
/* 	return EXIT_SUCCESS; */
/* } */
