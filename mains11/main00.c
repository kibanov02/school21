#include "../ex00/ft_foreach.c"
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	arr[100];
	int		i;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb == 0)
		ft_putchar2('0');
	if (nb < 0 && nb > -2147483648)
	{
		ft_putchar2('-');
		nb *= -1;
	}
	i = 0;
	while (nb > 0)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &arr[i - 1], 1);
		i--;
	}
}

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


int main(int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_foreach(arr, argc - 1, &ft_putnbr);
}