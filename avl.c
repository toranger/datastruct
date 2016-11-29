#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"avl.h"


int get_hight(Node* node){
	if(node == NULL)
		return -1;
	return node->hight;
}

Node* avl_init_node(int key){
	Node* tmp = (Node*)malloc(sizeof(Node));
	if(tmp == NULL)
		return NULL;
	tmp->left = NULL;
	tmp->pre = NULL;
	tmp->right = NULL;
	tmp->key = key;
	tmp->hight = 0;
	return tmp;
}

Tree* avl_init_tree(){
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	if(tree == NULL)
		return NULL;


}

void left_rotate(Tree* tree, Node* node){

}

void right_rotate(Tree* tree, Node* node){

}

Node* balance(Node* node){

}

Node* avl_search(Tree* tree, int key){

}

int avl_insert(Tree* tree, Node* node){

}
int avl_delete(Tree* tree, Node* node){

}

//test main function
int main(){

	return 0;
}
