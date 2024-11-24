/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:48:31 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/24 19:51:35 by zajaddad         ###   ########.fr       */
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
	while (i < len_s1 && *s1)
		str[i++] = *s1++;
	j = 0;
	while (j < len_s2 && *s2)
		str[i++] = *s2++;
	return (str);
}

void	join_content(char **content, char *buffer, int n_bytes)
{
	char	*content_place_holder;

	if (content == NULL || buffer == NULL)
		return ;
	buffer[n_bytes] = 0;
	content_place_holder = *content;
	*content = ft_strjoin(content_place_holder, buffer);
	free(buffer);
	free(content_place_holder);
}

char	*read_line(int fd, char *result, int *index)
{
	char	*buffer;
	char	*content;
	int		n_bytes;

	*index = get_new_line_index((content = result, result));
	if (result && *index)
		return (result);
	while (1)
	{
		buffer = (char *)malloc(((size_t)BUFFER_SIZE) + 1);
		if (buffer == NULL)
			return (free(content), NULL);
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes <= 0)
		{
			free(buffer);
			result = NULL;
			break ;
		}
		join_content(&content, buffer, n_bytes);
		*index = get_new_line_index(content);
		if (content == NULL || *index)
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

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(rest), rest = NULL);
	buffer = read_line(fd, rest, &i);
	if (buffer == NULL)
		return (rest = NULL);
	if (*buffer == 0)
		return (free(buffer), rest = NULL);
	rest = ft_strdup(buffer + i);
	if (!i)
		return (free(rest), rest = NULL, buffer);
	line = ft_substr(buffer, 0, i);
	if (line == NULL)
		return (free(buffer), free(rest), rest = NULL, buffer = NULL, NULL);
	return (free(buffer), buffer = NULL, line);
}
