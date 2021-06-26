#include "./ex00/ft_strcpy.c"
#include "./ex01/ft_strncpy.c"
#include "./ex02/ft_str_is_alpha.c"
#include "./ex03/ft_str_is_numeric.c"
#include "./ex04/ft_str_is_lowercase.c"
#include "./ex05/ft_str_is_uppercase.c"
#include "./ex06/ft_str_is_printable.c"
#include "./ex07/ft_strupcase.c"
#include "./ex08/ft_strlowcase.c"
#include "./ex09/ft_strcapitalize.c"
#include "./ex10/ft_strlcpy.c"
#include "./ex11/ft_putstr_non_printable.c"
#include <stdio.h>
#include <unistd.h>
int main()
{
	char a[5] = {'o', 'o', 'o', 'o', '\0'};
	char b[4] = {'s' ,'r', 'c', '\0'};
	ft_strcpy(a, b);
	int	i = 0;
	while (a[i] != '\0')
		printf("%c", a[i++]);

	printf("\n");
	printf("\n");

	char a1[4] = {'1', '1', '1', '\0'};
	char b1[5] = {'2', '2', '2', '2', '\0'};
	ft_strncpy(a1, b1, 5);
	i = 0;
	while (a1[i] != '\0')
	{
		printf("%c", a1[i++]);
	}
    
    printf("\n");
    printf("\n");
    
    int ex02 = ft_str_is_alpha("fdaf§sddfsdFDSfDS");
    printf("%d\n", ex02);
    
    printf("\n");
    printf("\n");
    
    int ex03 = ft_str_is_numeric("25151h35");
    printf("%d\n", ex03);
    
    printf("\n");
    printf("\n");
    
    int ex04 = ft_str_is_lowercase("gfdgsgsfdfgA");
    printf("%d\n", ex04);
    
    printf("\n");
    printf("\n");
    
    int ex05 = ft_str_is_uppercase("FDSFDSGDDGDS");
    printf("%d\n", ex05);
    
    printf("\n");
    printf("\n");
    
    int ex06 = ft_str_is_printable("ffgfgGRG\nRSG");
    printf("%d\n", ex06);
    
    printf("\n");
    printf("\n");
       
    char ex07[] = "Sdsadsadskyh";
    char* a7 = ft_strupcase(ex07);
    write(1, a7, 12);
    
    printf("\n");
    printf("\n");
       
    char ex08[] = "SdsaSFFdskyh";
    char* a8 = ft_strlowcase(ex08);
    write(1, a8, 12);
    
    printf("\n");
     printf("\n");
        
     char ex09[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
     char* a9 = ft_strcapitalize(ex09);
     write(1, a9, 61);
    
    printf("\n");
    printf("\n");
       
    char a10[] = "zzzzzzzzzz";
    char b10[] = "hello";
    int i10 = ft_strlcpy(a10, b10, 5);
    printf("%d\n", i10);
    write(1, a10, 6);
    
    printf("\n");
    printf("\n");
    
    char a11[] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(a11);
}
