#include <unistd.h>
#include <fcntl.h>

void	no_file(void)
{
	char	c[4097];
	int		fd;
	int		n;

	fd = open("map", O_TRUNC);
	close(fd);
	fd = open("map", O_WRONLY);
	n = read(1, c, 4096);
	c[n] = '\0';
	while (n)
	{
		write (fd, c, n);
		n = read(1, c, 4096);
		c[n] = '\0';
	}
	close(fd);
}
