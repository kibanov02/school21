#include <stdlib.h>

void	free_mtx(int **mtx)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}
