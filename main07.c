#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
//#include "ex04/"
//#include "ex05/"
#include <stdio.h>
int main()
{
	//ex00
	printf("****ex00****\n\n");

	printf("test1\n");
	char a00[] = "";
	printf("%s\n", ft_strdup(a00));

	printf("test2\n");
	char a00_1[] = "Hello";
	printf("%s\n", ft_strdup(a00_1));

	printf("test3\n");
	char a00_2[] = "H";
	printf("%s\n", ft_strdup(a00_2));

	printf("test4\n");
	char a00_3[] = "Ilvar krasavchik!!    ";
	printf("%s\n", ft_strdup(a00_3));

	//ex01
	printf("****ex01****\n\n");


	printf("test1\n");
	int *a01 = ft_range(10, 20);
	for (int i = 0; i < 10; i++)
		printf("%d ", a01[i]);
	printf("\n");

	printf("test2\n");
	//int *a01_1 = ft_range(2, 1);
	//printf("%s", a01_1);
	printf("\n");


	//ex02
	printf("****ex02****\n\n");


	printf("test1\n");
	int *b02;
	int a02 = ft_ultimate_range(&b02, 10, 20);
	printf("%d\n", a02);
	for (int i = 0; i < 10; i++)
		printf("%d ", b02[i]);
	printf("\n");


	//ex03
	printf("****ex03****\n\n");

	printf("test1\n");
	char *a03[2];
	char b03[] = "Aaaa";
	char c03[] = "bbb";
	a03[0] = b03;
	a03[1] = c03;
	char sep03[] = "zz";
	char *res03 = ft_strjoin(2, a03, sep03);
	printf("%s\n", res03);
}