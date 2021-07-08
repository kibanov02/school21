#include "../ex00/ft_create_elem.c"
#include "../ex05/ft_list_push_strs.c"
#include "../ex08/ft_list_reverse.c"
#include <stdio.h>

int	main(void)
{
	char	*arr[3];

	char	*s1 = "Last line\n";
	char	*s2 = "Second line\n";
	char	*s3 = "First line\n";
	arr[0] = s1;
	arr[1] = s2;
	arr[2] = s3;
	t_list	*res = ft_list_push_strs(3, arr);
	ft_list_reverse(&res);
	while (res)
	{
		printf("%s", (char *)(res->data));
		res = res->next;
	}
}
