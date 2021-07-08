#include "../ex00/ft_create_elem.c"
#include "../ex05/ft_list_push_strs.c"
#include "../ex12/ft_list_remove_if.c"
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}


int	main(void)
{
	char	*arr[3];

	char	*s1 = (char *)malloc(sizeof(char));
	char	*s2 = (char *)malloc(sizeof(char));
	char	*s3 = (char *)malloc(sizeof(char));
	*s1 = '3';
	*s2 = '2';
	*s3 = '1';
	arr[0] = s1;
	arr[1] = s2;
	arr[2] = s3;
	t_list	*res = ft_list_push_strs(3, arr);
	void *v_ptr;
	char ref = '2';
	v_ptr = &ref;
	ft_list_remove_if(&res, v_ptr, &ft_strcmp, &free);
	while (res)
	{
		printf("%s", (char *)(res->data));
		res = res->next;
	}
}
