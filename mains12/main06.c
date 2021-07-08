#include "../ex06/ft_list_clear.c"
#include "../ex05/ft_list_push_strs.c"

int main()
{
	char	*arr[3];

	char	*s1 = (char *)malloc(sizeof(char));
	char	*s2 = (char *)malloc(sizeof(char));
	char	*s3 = (char *)malloc(sizeof(char));
	*s1 = '1';
	*s2 = '2';
	*s3 = '3';
	arr[0] = s1;
	arr[1] = s2;
	arr[2] = s3;
	t_list	*res = ft_list_push_strs(3, arr);
	ft_list_clear(res, &free);
}