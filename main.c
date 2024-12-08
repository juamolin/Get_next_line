#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	char	buf[256];
	int	chars_read;

	fd = open("abc.txt", O_RDONLY);

	while ((chars_read = read(fd, buf, 10)))
	{
		buf[chars_read] = '\0';
		printf("buf -> %s\n", buf);
	}
}