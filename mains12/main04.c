#include "../ex04/ft_list_push_back.c"
#include <stdio.h>

int	main(void)
{
	t_list	*res;

	t_list	*begin = ft_create_elem("First line\n");
	t_list	*l1 = ft_create_elem("Second line\n");
	begin->next = l1;
	ft_list_push_back(&begin, "Third line");
	res = ft_list_last(begin);
	printf("%s", (char *)(res->data));
}
