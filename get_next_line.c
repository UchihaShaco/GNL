
/*
**	Write a function that returns a line read from a
**	file descriptor(fd).
**	Return value: 
**		Read line: correct behavior.
**		NULL: there is nothing else to read, or an error occurred
*/

/* 
save: Static variable to save the read bytes 
will  be used the next time the function is called
line: stores the current line combination
with  the part already read previously
buf:  Stores what is currently being read
read: Integer variable that counts how many bytes were read
n:    To know where the next line starts
str:  save the total string to be returned
temp: Temporarily store the save str

//Buf to store what was read (buf[BUFFER_SIZE])
// join the old line with the current line (strjoin)
// Return whenever it finds the end of the line
// remove from static_var what has already been returned
*/
#include "get_next_line.h"

char	*save_the_line(char **save);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			ler;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	ler = read (fd, buf, 2);
	if (ler == -1)
		return (NULL);
	while (ler > 0)
	{
		buf[ler] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		line = ft_strjoin(save, buf);
		free (save);
		save = line;
		ler = read(fd, buf, BUFFER_SIZE);
	}
	return (save_the_line(&save));
}

char	*save_the_line(char **save)
{
	int		n;
	char	*temporary;
	char	*str;

	if (!*save)
		return (NULL);
	n = ft_strchr(*save, '\n'); 
	if (n >= 0)
	{
		str = ft_substr(*save, 0, n + 1); 
		temporary = ft_substr(*save, n + 1, ft_strlen(*save) - n); 
		*save = temporary;
		if (**save != '\0')
			return (str);
	}
	else
		str = ft_strdup(*save);
	free(*save);
	*save = 0;
	return (str);
}