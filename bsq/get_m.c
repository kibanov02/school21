#include <unistd.h>

int	get_m(int fd)
{
	char	c;
	int		len;

	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			return (len);
		len++;
	}
	return (0);
}
