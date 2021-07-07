#include "../ex01/ft_map.c"
#include <stdio.h>
#include <stdlib.h>

int	my_isspace(char ch)
{
	if (ch == ' '
		|| ch == '\f'
		|| ch == '\n'
		|| ch == '\r'
		|| ch == '\t'
		|| ch == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	while (my_isspace(str[i]) != 0)
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	return (n * sign);
}


int	foo(int a)
{
	return a * 2;
}

int main(int argc, char **argv)
{
	int	*arr;
	int	i;
	int	*res;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	res = ft_map(arr, argc - 1, &foo);
	for(int i = 0; i < argc - 1; i++)
		printf("%d", res[i]);
}