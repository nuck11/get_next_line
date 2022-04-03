#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1 && s1[++i])
	{
		str[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		size;
	int		j;
	int		i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s) - 1)
		start = (unsigned int)ft_strlen(s);
	j = start - 1;
	size = 0;
	while (s[++j] && size < (int)len)
		size++;
	sub = malloc(size + 1);
	if (!sub)
		return (NULL);
	i = start - 1;
	j = 0;
	while (++i <= (int)start + size - 1)
	{
		sub[j] = s[i];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	int		count;

	count = 0;
	copy = (char *)malloc(ft_strlen(s) + 1);
	if (!s || !copy)
		return (NULL);
	while (s[count])
	{
		copy[count] = s[count];
		count++;
	}
	copy[count] = '\0';
	free(s);
	return (copy);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*home;

	home = (unsigned char *)s;
	i = -1;
	while (++i < n)
		home[i] = c;
	return (home);
}
