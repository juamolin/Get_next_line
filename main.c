#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR | O_CREAT);

	printf("fd of file%d\n", fd);
	write(1, "hello", 5);
	write(fd, "hello", 5);
	return 0;
}