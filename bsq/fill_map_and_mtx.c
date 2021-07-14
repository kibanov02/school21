#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

int	*fill_map_and_mtx(int fd, int **mtx, int *n_and_symbols, int m)
{
	char	ch;
	int		*max;
	int		i[2];
	int		n;

	max = (int *)malloc(sizeof(int) * 3);
	max[0] = 0;
	max[3] = n_and_symbols[3];
	n = read(fd, &ch, 1);
	while (ch != '\n')
		n = read(fd, &ch, 1);
	i[0] = 0;
	while (n && i[0] < n_and_symbols[0])
	{
		i[1] = 0;
		while (i[1] < m)
		{
			n = read(fd, &ch, 1);
			if (n == 0 || (ch != n_and_symbols[1]
					&& ch != n_and_symbols[2]
					&& ch != n_and_symbols[3]))
				return (0);
			if ((i[0] == 0 || i[1] == 0) && ch != n_and_symbols[2])
				mtx[i[0]][i[1]] = 1;
			else if (ch == n_and_symbols[2])
				mtx[i[0]][i[1]] = 0;
			else
				mtx[i[0]][i[1]] = ft_min(mtx[i[0] - 1][i[1]],
						mtx[i[0]][i[1] - 1], mtx[i[0] - 1][i[1] - 1]) + 1;
			if (mtx[i[0]][i[1]] > max[0])
			{
				max[0] = mtx[i[0]][i[1]];
				max[1] = i[0];
				max[2] = i[1];
			}
			i[1]++;
		}
		n = read(fd, &ch, 1);
		if (ch != '\n' || (n == 0 && i[0] < n_and_symbols[0]))
			return (0);
		i[0]++;
	}
	if (read(fd, &ch, 1) > 0)
		return (0);
	return (max);
}
