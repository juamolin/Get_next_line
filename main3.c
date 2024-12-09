
#include "get_next_line.h"

int	main(void)
{
	int		fd = 0;
	char	*text;

	fd = open("abc.txt", O_RDONLY);
	text = get_next_line(fd);
	while (text)
	{
		printf("%s", text);
		free(text);
		text = get_next_line(fd);
	}
	close(fd);
	return (0);
}
