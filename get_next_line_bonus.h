#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_SIZE 4096

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, const char *s2);

char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_strdup(char *s);

void	*ft_memset(void *s, int c, size_t n);

char	*get_next_line(int fd);

#endif
