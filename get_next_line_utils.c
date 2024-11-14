/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:28:33 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/14 10:43:02 by zajaddad         ###   ########.fr       */
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
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (str == NULL)
		return (NULL);
	// watchout
	(void)strlcpy(str, s1, len_s1 + 1);
	(void)strlcat(str, s2, len_s1 + len_s2 + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	// watchout
	memcpy(substr, &s[start], len);
	substr[len] = 0;
	return (substr);
}

