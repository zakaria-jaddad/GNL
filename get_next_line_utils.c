/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:28:33 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/15 23:20:51 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			len;
	unsigned char	*ptr;

	len = (count * size);
	ptr = (unsigned char *)malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (len--)
		ptr[len] = 0;
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	i = 0;
	ptr = (char *)ft_calloc(1, len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*substr;
	size_t			i;

	if (s == NULL || *s == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)ft_calloc(1, len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		substr[i++] = s[start++];
	return (substr);
}
