#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	check_and_make_res_buf(int n, int *res_buf, char *buf)
{
	if (n == 0)
		return (0);
	res_buf[0] = n;
	n = 1;
	while (n < 4)
	{
		if (buf[n] < 32)
			return (0);
		res_buf[n] = (int)buf[n];
		n++;
	}
	return (1);
}

int	*get_n(int fd)
{
	char	buf[5];
	int		*res_buf;
	int		r;
	int		n;

	res_buf = (int *)malloc(sizeof(int) * 4);
	r = read(fd, buf, 4);
	if (r < 4 || (buf[0] < '0' || buf[0] > '9'))
		return (0);
	n = buf[0] - '0';
	while (r && buf[4] != '\n')
	{
		r = read(fd, buf + 4, 1);
		if (r == 0 || buf[4] == '\n')
			break ;
		r = 0;
		while (r++ < 4)
			buf[r - 1] = buf[r];
		if (buf[0] < '0' || buf[0] > '9')
			return (0);
		n = 10 * n + (buf[0] - '0');
	}
	if (check_and_make_res_buf(n, res_buf, buf) == 0)
		return (0);
	return (res_buf);
}
