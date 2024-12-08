#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;

	fd = open("abc.txt", O_RDWR | O_CREAT | O_APPEND);

	dup2(fd, 1);

	write(1, "hello ", 6);
	return 0;
}