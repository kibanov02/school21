#include "./ex00/ft_strcmp.c"
#include <unistd.h>
#include <stdio.h>
int main()
{
	//ex00
    write(1, "///ex00///\n", 11);
    
    write(1, "test 1\n", 7);
    char a00[] = "z";
    char b00[] = "d";
    int i00 = ft_strcmp(a00, b00);
    write(1, "answer should be = 22\nyour answer is: ", 38);
    printf("%d\n\n", i00);
    
    write(1, "test 2\n", 7);
    char a00_1[] = "\n";
    char b00_1[] = " ";
    int i00_1 = ft_strcmp(a00_1, b00_1);
    write(1, "answer should be = -22\nyour answer is: ", 39);
    printf("%d\n\n", i00_1);
    
    write(1, "test 3\n", 7);
    char a00_2[] = " ";
    char b00_2[] = " ";
    int i00_2 = ft_strcmp(a00_2, b00_2);
    write(1, "answer should be = 0\nyour answer is: ", 37);
    printf("%d", i00_2);
    
    //ex01
    
}
