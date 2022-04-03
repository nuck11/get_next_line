#include "get_next_line.h"

int	nl_check(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

void	split(char *source, char **s1, char **s2)
{
	int		i;
	int		r_len;
	char	*to_s1;

	i = 0;
	*s2 = NULL;
	r_len = ft_strlen (source);
	while (source && source[i] != '\n' && i < r_len)
		i++;
	to_s1 = ft_substr (source, 0, i + 1);
	*s1 = ft_strjoin (*s1, to_s1);
	free (to_s1);
	if (r_len - i - 1 > 0)
		*s2 = ft_substr (source, i + 1, r_len - i - 1);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*reading;
	char		*temp_resto;
	static char	*resto;

	buff = NULL;
	if (resto)
	{
		temp_resto = ft_strdup (resto);
		split (temp_resto, &buff, &resto);
		free (temp_resto);
	}
	reading = malloc (BUFFER_SIZE + 1);
	ft_memset (reading, 0, BUFFER_SIZE + 1);
	while (!nl_check (buff) && read (fd, reading, BUFFER_SIZE) > 0)
	{
		split (reading, &buff, &resto);
		ft_memset (reading, 0, BUFFER_SIZE);
	}
	free (reading);
	return (buff);
}
