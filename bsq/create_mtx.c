#include <stdlib.h>

int	**create_mtx(int m)
{
	int	**mtx;
	int	i;

	i = 0;
	mtx = (int **)malloc(sizeof(int *) * 2);
	if (!mtx)
		return (NULL);
	while (i < 2)
	{
		mtx[i] = (int *)malloc(sizeof(int) * m);
		i++;
	}
	return (mtx);
}
