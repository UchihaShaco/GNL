

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (*s1)
		new[++i] = *s1++;
	while (*s2)
		new[++i] = *s2++;
	new[++i] = '\0';
	return (new);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*_substr;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (i < len)
		len = i;
	if (start > i)
		return ("");
	_substr = malloc(len + 1);
	if (!_substr)
		return (NULL);
	i = -1;
	while (str[++i] && i < len)
		_substr[i] = str[start++];
	_substr[i] = '\0';
	return (_substr);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * i + 1);
	if (!(cpy))
		return (NULL);
	i = -1;
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (char )c)
			return (i);
	return (-1);
}
