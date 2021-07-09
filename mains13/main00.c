#include "../ex00/btree_create_node.c"
#include <stdio.h>

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

	printf("Node1 item: %d\n", *(int *)(node1->item));
	printf("Node1 left: %p\n", (node1->left));
	printf("Node1 right: %p\n\n", (node1->right));

	printf("Node2 item: %d\n", *(int *)(node2->item));
	printf("Node2 left: %p\n", (node2->left));
	printf("Node2 right: %p\n\n", (node2->right));

	printf("Node3 item: %d\n", *(int *)(node3->item));
	printf("Node3 left: %p\n", (node3->left));
	printf("Node3 right: %p\n\n", (node3->right));

	printf("Node4 item: %d\n", *(int *)(node4->item));
	printf("Node4 left: %p\n", (node4->left));
	printf("Node4 right: %p\n\n", (node4->right));

	printf("Node5 item: %d\n", *(int *)(node5->item));
	printf("Node5 left: %p\n", (node5->left));
	printf("Node5 right: %p\n", (node5->right));
}