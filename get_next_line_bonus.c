/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:49:15 by jalwahei          #+#    #+#             */
/*   Updated: 2022/11/13 19:38:52 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1)
{
	int		s1_len;
	char	*str_copy;

	s1_len = ft_strlen(s1);
	str_copy = malloc(sizeof(*str_copy) * (1));
	str_copy[0] = '\0';
	return (str_copy);
}

char	*read_line(int fd, char *static_buffer)
{
	int		k;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	k = 1;
	if (!static_buffer)
		static_buffer = ft_strdup("");
	while (!ft_strchr(static_buffer, '\n') && k != 0)
	{
		k = read(fd, buffer, BUFFER_SIZE);
		if (k == -1)
		{
			free(buffer);
			free(static_buffer);
			return (NULL);
		}
		buffer[k] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*ft_getline(char *read)
{
	char	*line;
	int		i;

	i = 0;
	if (!read[i])
		return (NULL);
	while (read[i] && read[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (read[i] && read[i] != '\n')
	{
		line[i] = read[i];
		i++;
	}
	if (read[i] == '\n' || read[i] == '\0')
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_free(char *buffer)
{
	int		i;
	int		j;
	char	*saving;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	saving = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!saving)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		saving[j++] = buffer[i++];
	saving[j] = '\0';
	free(buffer);
	return (saving);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd]);
	buffer[fd] = ft_free(buffer[fd]);
	return (line);
}
