/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:48:31 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/14 11:30:25 by zajaddad         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	str = (char *)ft_calloc(1, len_s1 + len_s2 + 1);
	if (str == NULL)
		return (NULL);
	while (i < len_s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2 && s2[j])
		str[i++] = s2[j++];
	return (str);
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
		return (line = ft_strdup(buffer), free(buffer), free(rest), rest = NULL,
			line);
	line = ft_substr(buffer, 0, i);
	if (line == NULL || *line == 0)
		return (NULL);
	return (free(buffer), line);
}
