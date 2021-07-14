#include <stdlib.h>

void	free_mtx(int **mtx, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}
