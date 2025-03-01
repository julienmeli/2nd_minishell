#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("the missing file", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	close(fd);
	return (0);
}
