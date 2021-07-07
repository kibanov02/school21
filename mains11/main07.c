#include "../ex07/ft_advanced_sort_string_tab.c"
#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (len >= 0)
	{
		dest[len] = src[len];
		len--;
	}
	return (dest);
}

void	print(char **argv)
{
	char	*name;
	int		i;

	i = 0;
	while (argv[i])
	{
		name = argv[i];
		while (*name != '\0')
		{
			write(1, name, 1);
			name++;
		}
		*name = '\n';
		write(1, name, 1);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	char **argv1;
	int i;

	if (argc == 1)
		return (0);
	argv1 = (char **)malloc(sizeof(char *) * (argc));
	i = 1;
	while (i < argc)
	{
		argv1[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	argv1[i - 1] = NULL;
	ft_advanced_sort_string_tab(argv1, &ft_strcmp);
	print(argv1);
}
