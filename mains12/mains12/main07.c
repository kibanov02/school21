#include "../ex00/ft_create_elem.c"
#include "../ex05/ft_list_push_strs.c"
#include "../ex07/ft_list_at.c"
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
	res = ft_list_at(res, 2);
	printf("Answer should be: Last line\n");
	printf("%s", (char *)res->data);
}
