#include "../ex03/ft_count_if.c"
#include <stdio.h>
#include <stdlib.h>

int	foo(char *a)
{
	if (a[0] != '\0' && a[1] == 'a')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	char	**arr;
	int	i;

	arr = (char **)malloc(sizeof(char *) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = argv[i];
		i++;
	}
	printf("%d", ft_count_if(arr, argc - 1, &foo));
}