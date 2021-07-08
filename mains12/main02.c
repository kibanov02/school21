#include "../ex02/ft_list_size.c"
#include "../ex00/ft_create_elem.c"
#include "../ex02/ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*l;
	t_list	*s;
	char	*str;

	str = "First line\n";
	l = ft_create_elem(str);
	s = ft_create_elem("New first line\n");
	l->next = s;
	printf("%d", ft_list_size(l));
}
