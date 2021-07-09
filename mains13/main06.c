#include "../ex00/btree_create_node.c"
#include "../ex06/btree_level_count.c"
#include "../ex04/btree_insert_data.c"
#include <stdio.h>

void f(void *a)
{
	printf("%d\n", *(int *)a);
}

int cmp(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	t_btree	*node1;
	int a1 = 1;

	node1 = btree_create_node(&a1);

	t_btree	*node2;
	int a2 = 2;

	node2 = btree_create_node(&a2);

	t_btree	*node3;
	int a3 = 3;

	node3 = btree_create_node(&a3);

	t_btree	*node4;
	int a4 = 4;

	node4 = btree_create_node(&a4);

	t_btree	*node5;
	int a5 = 5;

	node5 = btree_create_node(&a5);


//	4-5
//	|
//	2-3
//	|
//	1

	node4->right = node5;
	node4->left = node2;
	node2->right = node3;
	node2->left = node1;


	t_btree	*node6;
	int a6 = 4;

	node6 = btree_create_node(&a6);
	btree_insert_data(&node4, &a6, &cmp);

	int res = btree_level_count(node4);
	printf("It shoul return 3\n");
	printf("%d\n", res);
}
