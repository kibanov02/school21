#include "../ex01/ft_list_push_front.c"
#include "../ex01/ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list	*l;
	char	*str;

	str = "First line\n";
	l = ft_create_elem(str);
	ft_list_push_front(&l, "New first line\n");
	while (l)
	{	
		printf("%s", (char *)(l->data));
		l = l->next;
	}
}
