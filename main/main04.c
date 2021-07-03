#include "ft_strs_to_tab.c"

int main()
{
	char *a[2];
	char b[] = "aa";
	char c[] = "bb";
	a[0] = b;
	a[1] = c;
	ft_strs_to_tab(2, a);
}