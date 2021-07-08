#include "../ex00/ft_create_elem.c"
#include "../ex05/ft_list_push_strs.c"
#include "../ex13/ft_list_merge.c"
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

	char	*arr1[3];

	char	*s11 = "Last line\n";
	char	*s21 = "Second line\n";
	char	*s31 = "First line\n";
	arr1[0] = s11;
	arr1[1] = s21;
	arr1[2] = s31;
	t_list	*res1 = ft_list_push_strs(3, arr1);
	ft_list_merge(&res, res1);
	while (res)
	{
		printf("%s", (char *)(res->data));
		res = res->next;
	}
}
