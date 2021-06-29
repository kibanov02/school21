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
    printf("answer should be = zzzzz\nyour answer is: \n");
    ft_putstr(a01);
    printf("\n\n");
    
    printf("test 2\n");
    char a01_1[] = "";
    printf("answer should be = \nyour answer is: \n");
    ft_putstr(a01_1);
    printf("\n\n");
   
    printf("test 3\n");
    char a01_2[] = "aaa\0aa";
    printf("answer should be = aaa\nyour answer is: \n");
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

    //ex03
    printf("****ex03****\n");
    
    printf("test 1\n");
    char a03[] = "asfasfas";
    printf("answer should be = 0\nyour answer is: ");
    printf("%d", ft_atoi(a03));
    printf("\n\n");
    
    printf("test 2\n");
    char a03_1[] = "\n\n\n\n\n\t\t\t\t\t++---+++--";
    printf("answer should be = 0\nyour answer is: ");
    printf("%d", ft_atoi(a03_1));
    printf("\n\n");
   
    printf("test 3\n");
    char a03_2[] = "    +-+-++--++--2147483647";
    printf("answer should be = 2147483647\nyour answer is: ");
    printf("%d", ft_atoi(a03_2));
    printf("\n\n");

    printf("test 4\n");
    char a03_3[] = "-2147483648";
    printf("answer should be = -2147483648\nyour answer is: ");
    printf("%d", ft_atoi(a03_3));
    printf("\n\n");

    printf("test 5\n");
    char a03_4[] = "      ----------++++++++50";
    printf("answer should be = 50\nyour answer is: ");
    printf("%d", ft_atoi(a03_4));
    printf("\n\n");

    //ex04
    printf("****ex04****\n");
    
    printf("test 1\n");
    char a04[] = "qwerty";
    printf("answer should be = wrwr\nyour answer is: \n");
    ft_putnbr_base(333, a04);
    printf("\n\n");

    printf("test 2\n");
    char a04_1[] = "q";
    printf("answer should be = \nyour answer is: \n");
    ft_putnbr_base(333, a04_1);
    printf("\n\n");

    printf("test 3\n");
    char a04_2[] = "./']";
    printf("answer should be = //\nyour answer is: \n");
    ft_putnbr_base(5, a04_2);
    printf("\n\n");

    printf("test 4\n");
    char a04_3[] = "qwerty-";
    printf("answer should be = \nyour answer is: \n");
    ft_putnbr_base(333, a04_3);
    printf("\n\n");

    printf("test 5\n");
    char a04_4[] = "qwertyq";
    printf("answer should be = \nyour answer is: \n");
    ft_putnbr_base(333, a04_4);
    printf("\n\n");

    printf("test 6\n");
    char a04_5[] = "q\nerty";
    printf("answer should be = \nyour answer is: \n");
    ft_putnbr_base(333, a04_5);
    printf("\n\n");

    //ex05
    printf("****ex05****\n");
    
    printf("test 1\n");
    char a05[] = "wrwr";
    char b05[] = "qwerty";
    printf("answer should be = 333\nyour answer is: \n");
    printf("%d", ft_atoi_base(a05, b05));
    printf("\n\n");

    printf("test 2\n");
    char a05_1[] = "q";
    char b05_1[] = "qwert";
    printf("answer should be = 0\nyour answer is: \n");
    printf("%d", ft_atoi_base(a05_1, b05_1));
    printf("\n\n");

    printf("test 3\n");
    char a05_2[] = "        --+--wrw r";
    char b05_2[] = "qwerty";
    printf("answer should be = \nyour answer is: \n");
    printf("%d", ft_atoi_base(a05_2, b05_2));
    printf("\n\n");

    printf("test 4\n");
    char a05_3[] = "  \n \r t";
    char b05_3[] = "qwerty";
    printf("answer should be = 4\nyour answer is: \n");
    printf("%d", ft_atoi_base(a05_3, b05_3));
    printf("\n\n");

    printf("test 5\n");
    char a05_4[] = "w qweqwrqwe";
    char b05_4[] = "qwerty";
    printf("answer should be = 1\nyour answer is: \n");
    printf("%d", ft_atoi_base(a05_4, b05_4));
    printf("\n\n");

    printf("test 6\n");
    char a05_5[] = "     \t -+-+ wrwr";
    char b05_5[] = "qwerty";
    printf("answer should be = 0\nyour answer is: \n");
    printf("%d", ft_atoi_base(a05_5, b05_5));
    printf("\n\n");
}
