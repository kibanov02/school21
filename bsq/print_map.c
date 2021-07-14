#include <unistd.h>

void	print_map(int fd, int *max)
{
	char	ch;
	int		i;
	int		j;

	read(fd, &ch, 1);
	while (ch != '\n')
		read(fd, &ch, 1);
	i = 0;
	j = 0;
	while (read(fd, &ch, 1))
	{
		if ((max[1] >= i && max[1] - i < max[0])
			&& (max[2] >= j && max[2] - j < max[0]))
			ch = max[3];
		write(1, &ch, 1);
		j++;
		if (ch == '\n')
		{
			j = 0;
			i++;
		}
	}
}
/*
int	main(void)
{
	int fd = open("a", O_RDONLY);
	if (fd == -1)
		return (0);
	char map_symbols[3];
	map_symbols[0] = '.';
	map_symbols[1] = 'o';
	map_symbols[2] = 'x';
	int *mtx[9];
	for (int i = 0; i < 9; i++)
	{
	    mtx[i] = (int *)malloc(sizeof(int) * 27);
	}
	int sizes[2];
	sizes[0] = 9;
	sizes[1] = 27;
	int *max = fill_map_and_mtx(fd, map_symbols, (int **)mtx, sizes);
	close(fd);
	fd = open("a", O_RDONLY);
	if (fd == -1)
		return (0);
	print_map(fd, max, sizes[0], sizes[1]);
}*/