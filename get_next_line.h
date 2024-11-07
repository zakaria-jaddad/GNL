#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif 

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// typedef struct s_list {
// 	char *content;
// 	struct s_list *next;
//
// } t_list;

char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif


