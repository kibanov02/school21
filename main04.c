#include "./ex00/ft_strlen.c"
#include "./ex01/ft_putstr.c"
#include "./ex02/ft_putnbr.c"
#include "./ex03/ft_atoi.c"
#include "./ex04/ft_putnbr_base.c"
#include "./ex05/ft_atoi_base.c"
#include <unistd.h>
#include <stdio.h>
int main()
{
	//ex00
    printf("****ex00****\n");
    
    printf("test 1\n");
    char a00[] = "zzzzz";
    int i00 = ft_strlen(a00);
    printf("answer should be = 5\nyour answer is: ");
    printf("%d\n\n", i00);
    
    printf("test 2\n");
    char a00_1[] = "";
    int i00_1 = ft_strlen(a00_1);
    printf("answer should be = 0\nyour answer is: ");
    printf("%d\n\n", i00_1);
    
    printf("test 3\n");
    char a00_2[] = "aaa\0aa";
    int i00_2 = ft_strlen(a00_2);
    printf("answer should be = 3\nyour answer is: ");
    printf("%d\n\n", i00_2);

    //ex01
    printf("****ex01****\n");
    
    printf("test 1\n");
    char a01[] = "zzzzz";
    printf("answer should be = zzzzz\nyour answer is: ");
    ft_putstr(a01);
    printf("\n\n");
    
    printf("test 2\n");
    char a01_1[] = "";
    printf("answer should be = \nyour answer is: ");
    ft_putstr(a01_1);
    printf("\n\n");
   
    printf("test 3\n");
    char a01_2[] = "aaa\0aa";
    printf("answer should be = aaa\nyour answer is: ");
    ft_putstr(a01_2);
    printf("\n\n");

    //ex02
    printf("****ex02****\n");
    
    printf("test 1\n");
    int i02 = 42;
    printf("answer should be = 42\nyour answer is: ");
    printf("%d",  i02);
    printf("\n\n");
    
    printf("test 2\n");
    int i02_1 = -42;
    printf("answer should be = -42\nyour answer is: ");
    printf("%d",  i02_1);
    printf("\n\n");
   
    printf("test 3\n");
    int i02_2 = 0;
    printf("answer should be = 0\nyour answer is: ");
    printf("%d",  i02_2);
    printf("\n\n");

    printf("test 4\n");
    int i02_3 = 2147483647;
    printf("answer should be = 2147483647\nyour answer is: ");
    printf("%d",  i02_3);
    printf("\n\n");

    printf("test 5\n");
    int i02_4 = -2147483648;
    printf("answer should be = -2147483648\nyour answer is: ");
    printf("%d",  i02_4);
    printf("\n\n");
}
