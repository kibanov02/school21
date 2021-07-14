#include "ft.h"

int	file_input(char *filename, int fd)
{
	int		m;
	int		**mtx;
	int		*max;
	int		*n_and_symbols;

	n_and_symbols = get_n(fd);
	m = get_m(fd);
	if (n_and_symbols == 0 || m == 0)
		return (1);
	close(fd);
	mtx = create_mtx(m);
	fd = open(filename, O_RDONLY);
	max = fill_map_and_mtx(fd, mtx, n_and_symbols, m);
	if (max == 0)
		return (1);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	print_map(fd, max);
	close(fd);
	free(max);
	free(n_and_symbols);
	free_mtx(mtx);
	return (0);
}

void	standart_input(void)
{
	int	fd;

	no_file();
	fd = open("map", O_RDONLY);
	write(1, "\n", 1);
	file_input("map", fd);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
	{
		standart_input();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_error();
		else if (file_input(argv[i], fd))
			print_error();
		i++;
	}
}
