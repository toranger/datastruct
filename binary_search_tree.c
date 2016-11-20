#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binary_search_tree.h"















//test main function
int main()
{
	int ret;
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	ret = bin_tree_init(tree);
	Node* node = (Node*)malloc(sizeof(Node));
	ret = bin_tree_node(node);
	
	


	return 0;
}

