

#include "get_next_line.h"
#include "string.h"
#include <assert.h>
int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	assert (get_next_line(1000) == NULL);
	 /* 3 */ assert (get_next_line(fd) == NULL);
	  /* 2 */ assert (strncmp(get_next_line(fd), "1", 1) == 0);
		 /* 3 */ assert (get_next_line(fd) == NULL);
	close(fd);
}
