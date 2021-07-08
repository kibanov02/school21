#include "../ex00/ft_create_elem.c"
#include "../ex05/ft_list_push_strs.c"
#include "../ex11/ft_list_find.c"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}


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
	void *v_ptr;
	char ref[] = "Second line\n";
	v_ptr = ref;
	res = ft_list_find(res, v_ptr, &ft_strcmp);
	printf("The answer: Second line\n");
	printf("%s", (char *)(res->data));
}
