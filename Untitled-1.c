#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return(c);
}

int* fill_map_and_mtx(int fd, char* map_symbols, int** mtx, int* sizes)
{
	char ch;
	int i;
	int j;
	int* max;

	max = (int*)malloc(sizeof(int) * 3);
	max[0] = 0;
	read(fd, &ch, 1);
	while (ch != '\n')
		read(fd, &ch, 1);
	i = 0;
	while (i < sizes[0])
	{
		j = 0;
		while (j < sizes[1])
		{
			read(fd, &ch, 1);
			if ((i == 0 || j == 0) && ch != map_symbols[1])
				mtx[i][j] = 1;
			else if (ch == map_symbols[1])
				mtx[i][j] = 0;
			else
				mtx[i][j] = ft_min(mtx[i - 1][j], mtx[i][j - 1], mtx[i - 1][j - 1]) + 1;
			if (mtx[i][j] > max[0])
			{
				max[0] = mtx[i][j];
				max[1] = i;
				max[2] = j;
			}
			printf("%d ", mtx[i][j]);
			//printf("%d ", ch);
			j++;
		}
		printf("\n");
		read(fd, &ch, 1);
		printf("%d ", ch);
		read(fd, &ch, 1);
		printf("%d\n", ch);
		i++;
	}
	return (max);
}

int	main(void)
{
	int fd = open("a.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	char map_symbols[3];
	map_symbols[0] = '.';
	map_symbols[1] = 'o';
	map_symbols[2] = 'x';
	int* mtx[9];
	for (int i = 0; i < 9; i++)
		mtx[i] = (int*)malloc(sizeof(int) * 27);
	int sizes[2];
	sizes[0] = 9;
	sizes[1] = 27;
	int* max = fill_map_and_mtx(fd, map_symbols, (int**)mtx, sizes);
	printf("%d", max[0]);
}