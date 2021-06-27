#include "./ex00/ft_strcmp.c"
#include "./ex01/ft_strncmp.c"
#include "./ex02/ft_strcat.c"
#include "./ex03/ft_strncat.c"
#include "./ex04/ft_strstr.c"
#include "./ex05/ft_strlcat.c"
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
    printf("%d\n\n", i00_2);
    
    //ex01
    write(1, "///ex01///\n", 11);
    
    write(1, "test 1\n", 7);
    char a01[] = "z";
    char b01[] = "d";
    int i01 = ft_strncmp(a01, b01, 1);
    write(1, "answer should be = 22\nyour answer is: ", 38);
    printf("%d\n\n", i01);
    
    write(1, "test 2\n", 7);
    char a01_1[] = "zfdafdsfs";
    char b01_1[] = "zfsfa";
    int i01_1 = ft_strncmp(a01_1, b01_1, 2);
    write(1, "answer should be = 0\nyour answer is: ", 37);
    printf("%d\n\n", i01_1);
    
    write(1, "test 3\n", 7);
    char a01_2[] = "zfbfadsfs";
    char b01_2[] = "zfbfb";
    int i01_2 = ft_strncmp(a01_2, b01_2, 5);
    write(1, "answer should be = -1\nyour answer is: ", 38);
    printf("%d\n\n", i01_2);
    
    //ex02
    write(1, "///ex02///\n", 11);
    
    write(1, "test 1\n", 7);
    
    char a02[30] = "string";
    char b02[120] = "ddas";
    ft_strcat(a02, b02);
    printf("answer should be = stringddas\nyour answer is: ");
    for(int i = 0; a02[i]; i++)
        printf("%c", a02[i]);
    printf("%c", '\n');
    
    write(1, "test 2\n", 7);
    
    char a02_1[30] = "string";
    char b02_1[55] = "";
    ft_strcat(a02_1, b02_1);
    printf("answer should be = string\nyour answer is: ");
    for(int i = 0; a02_1[i]; i++)
        printf("%c", a02_1[i]);
    printf("%c", '\n');
    
    write(1, "test 3\n", 7);
    
    char a02_2[30] = "";
    char b02_2[32] = "ddas";
    ft_strcat(a02_2, b02_2);
    printf("answer should be = ddas\nyour answer is: ");
    write(1, a02_2, 20);
    for(int i = 0; a02_2[i]; i++)
          printf("%c", a02_2[i]);
    printf("%c", '\n');
    
    //ex03
    write(1, "///ex03///\n", 11);
    
    write(1, "test 1\n", 7);
    
    char a03[30] = "string";
    char b03[120] = "ddas";
    ft_strncat(a03, b03, 2);
    printf("answer should be = stringdd\nyour answer is: ");
    for(int i = 0; a03[i]; i++)
        printf("%c", a03[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
    write(1, "test 2\n", 7);
    
    char a03_1[30] = "string";
    char b03_1[55] = "ggblin";
    ft_strncat(a03_1, b03_1, 10);
    printf("answer should be = stringggblin\nyour answer is: ");
    for(int i = 0; a03_1[i]; i++)
        printf("%c", a03_1[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
    write(1, "test 3\n", 7);
    
    char a03_2[30] = "";
    char b03_2[32] = "";
    ft_strncat(a03_2, b03_2, 3);
    printf("answer should be = \nyour answer is: ");
    for(int i = 0; a03_2[i]; i++)
          printf("%c", a03_2[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
      write(1, "test 4\n", 7);
    
   char a03_3[30] = "string";
   char b03_3[32] = "ggg";
   ft_strncat(a03_3, b03_3, 0);
   printf("answer should be = string\nyour answer is: ");
   for(int i = 0; a03_3[i]; i++)
         printf("%c", a03_3[i]);
   printf("%c", '\n');
    printf("%c", '\n');
    
    
    //ex04
    write(1, "///ex04///\n", 11);
    
    write(1, "test 1\n", 7);
    
    char a04[30] = "";
    char b04[120] = "";
    char* ch04 = ft_strstr(a04, b04);
    printf("answer should be = \nyour answer is: ");
    for(int i = 0; ch04[i]; i++)
        printf("%c", ch04[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
    write(1, "test 2\n", 7);
    
    char a04_1[30] = "string";
    char b04_1[55] = "ing";
    char* ch04_1 = ft_strstr(a04_1, b04_1);
    printf("answer should be = ing\nyour answer is: ");
    for(int i = 0; ch04_1[i]; i++)
        printf("%c", ch04_1[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
    write(1, "test 3\n", 7);
    
    char a04_2[30] = "string";
    char b04_2[32] = "str";
    char* ch04_2 = ft_strstr(a04_2, b04_2);
    printf("answer should be = string\nyour answer is: ");
    for(int i = 0; ch04_2[i]; i++)
          printf("%c", ch04_2[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
     write(1, "test 4\n", 7);
    
    char a04_3[30] = "string";
    char b04_3[32] = "";
    char* ch04_3 = ft_strstr(a04_3, b04_3);
    printf("answer should be = string\nyour answer is: ");
    for(int i = 0; ch04_3[i]; i++)
          printf("%c", ch04_3[i]);
    printf("%c", '\n');
    printf("%c", '\n');
    
    //ex05
   write(1, "///ex05///\n", 11);
   
   write(1, "test 1\n", 7);
   
   char a05[30] = "string";
   char b05[120] = "ggg";
   int i05 = ft_strlcat(a05, b05, 4);
   printf("answer should be = 9\nyour answer is: ");
    printf("%d", i05);
   printf("%c", '\n');
   printf("%c", '\n');
   
   write(1, "test 2\n", 7);
   
   char a05_1[30] = "string";
   char b05_1[55] = "c";
   int i05_1 = ft_strlcat(a05_1, b05_1, 4);
   printf("answer should be = 7\nyour answer is: ");
   printf("%d", i05_1);
   printf("%c", '\n');
   printf("%c", '\n');
   
 /*  write(1, "test 3\n", 7);
   
   char a05_2[30] = "";
   char b05_2[32] = "str";
   int i05_2 = ft_strlcat(a05_2, b05_2);
   printf("answer should be = string\nyour answer is: ");
   printf("%d", i05);
   printf("%c", '\n');
   printf("%c", '\n');
   
    write(1, "test 4\n", 7);
   
   char a04_3[30] = "string";
   char b04_3[32] = "";
   int i05_3 = ft_strlcat(a04_3, b04_3);
   printf("answer should be = string\nyour answer is: ");
   printf("%d", i05);
   printf("%c", '\n');
   printf("%c", '\n');*/
}
