#include <stdlib.h>

int	**create_mtx(int n, int m)
{
	int	**mtx;
	int	i;

	i = 0;
	mtx = (int **)malloc(sizeof(int *) * n);
	if (!mtx)
		return (NULL);
	while (i < n)
	{
		mtx[i] = (int *)malloc(sizeof(int) * m);
		i++;
	}
	return (mtx);
}
