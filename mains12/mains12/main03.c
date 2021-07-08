#include "../ex03/ft_list_last.c"
#include "../ex00/ft_create_elem.c"
#include "../ex03/ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*l;
	t_list	*s;
	t_list	*res;
	char	*str;

	str = "First line\n";
	l = ft_create_elem(str);
	s = ft_create_elem("Second line\n");
	l->next = s;
	res = ft_list_last(l);
	printf("%s\n", "The answer should be: Second line");
	printf("%s", (char *)(res->data));
}
