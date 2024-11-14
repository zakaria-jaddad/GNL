/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:48:31 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/13 23:51:36 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_new_line_index(char *s)
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

void	join_content(char **content, char *buffer)
{
	char	*content_place_holder;

	if (content == NULL || buffer == NULL)
		return ;
	content_place_holder = *content;
	*content = ft_strjoin(content_place_holder, buffer);
	free(buffer);
	free(content_place_holder);
}

char	*read_line(int fd, char *result)
{
	char	*buffer;
	char	*content;

	if (result && get_new_line_index(result))
		return (result);
	content = result;
	while (1)
	{
		buffer = (char *)ft_calloc(sizeof(char), (size_t)(BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (free(content), NULL);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			free(buffer);
			break ;
		}
		join_content(&content, buffer);
		if (content == NULL || get_new_line_index(content))
			break ;
	}
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*buffer;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, rest);
	if (buffer == NULL || *buffer == 0)
		return (free(rest), rest = NULL, NULL);
	i = get_new_line_index(buffer);
	rest = ft_strdup(buffer + i);
	if (!i)
		return (line = ft_strdup(buffer),
			free(buffer), free(rest), rest = NULL, line);
	line = ft_substr(buffer, 0, i);
	if (line == NULL || *line == 0)
		return (NULL);
	return (free(buffer), line);
}
