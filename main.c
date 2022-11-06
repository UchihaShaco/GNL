#include "get_next_line.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	fd = open("test.txt", O_RDONLY);	
// 	printf("%d\n", fd);
// 	line = get_next_line(fd);
// 	printf("%s", line);

// 	 while (line != NULL)
// 	 {
// 	 	printf("%s", line);
// 	 	free(line);
// 	 	line = get_next_line(fd);
// 	 }
// 	return (0);
// }
// int	main(void)
// {
// 	int	fd;
// 	char	*line;

// 	line = NULL;

// // printf("ERROR:there are more than one file as an input!\n");
// 	fd = open("test.txt", O_RDONLY);		
// 	line = get_next_line(fd);
// printf("%s" , line);
// 	line = get_next_line(fd);
// printf("%s" , line);
// 	line = get_next_line(fd);
// printf("%s" , line);
// 	line = get_next_line(fd);
// printf("%s" , line);
// 	return (0);
// }
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	// fd = 42;
	// printf("%d\n", fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	 printf("%s", line);
	return (0);
}
