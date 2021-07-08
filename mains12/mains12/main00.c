#include "../ex00/ft_create_elem.c"
#include "../ex00/ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*l;
	char	*str;

	str = "Right string\n";
	l = ft_create_elem(str);
	printf("%s", (char *)(l->data));
}
