#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("missing file", O_RDONLY);
	if (fd < 0)
	{
		write(2, strerror(errno), strlen(strerror(errno)));
		write(2, "\n", 1);
		return (1);
	}
	close(fd);
	return (0);
}
