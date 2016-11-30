/**
 * @file avl.c node contains the hight
 * @brief node contains the hight
 * the hight is the max number in {left , right} +1
 * ps: when i use the function similar to rb tree insert
 * i found avl tree insert a node change the every node member in this son tree
 * the hight all changed but when final to insert need to count the every node in 
 * son tree hight, so i decide to use the recursive way to realize the avl insert
 * @author tmd
 * @version 1.0
 * @date 2016-12-01
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"avl.h"


int get_hight(Node* node){
	if(node == NULL)
		return 0;
	return node->hight;
}
int max(int a, int b){//avl tree not exist equal number
	return a>b?a:b;
}
/**
 * @brief get_stat  get the hight difference 
 * case1 or case2 left-left >1
 * case3 or case4 right-right <-1
 * @param node
 * @return 
 */
int get_stat(Node* node){
	if(node == NULL)
		exit(1);
	return get_hight(node->left)-get_hight(node->right);	
}

Node* avl_init_node(int key){
	Node* tmp = (Node*)malloc(sizeof(Node));
	if(tmp == NULL)
		return NULL;
	tmp->left = NULL;
	tmp->pre = NULL;
	tmp->right = NULL;
	tmp->key = key;
	tmp->hight = 1;
	return tmp;
}

Tree* avl_init_tree(){
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	if(tree == NULL)
		return NULL;
	return tree;

}
//return the new root node
Node* left_rotate(Tree* tree, Node* node){
	Node* y = node->right;
	node->right = y->left;
	if(y->left != NULL)
		y->left->pre = node;
	y->pre = node->pre;	
	if(node->pre == NULL){
		tree->root = y;	
	}else if(node->pre->left == node){
		node->pre->left = y;	
	}else{
		node->pre->right = y;	
	}
	y->left = node;
	node->pre = y;
	//change the hight
	node->hight = max(get_hight(node->left),
			get_hight(node->right)) + 1;
	y->hight = max(get_hight(y->left),
			get_hight(y->right)) + 1;
	
	
	return y;
}

Node* right_rotate(Tree* tree, Node* node){
	Node* y = node->left;
	node->left = y->right;
	if(y->right != NULL)
		y->right->pre = node;
	y->pre = node->pre;
	if(node->pre == NULL){
		tree->root = y;	
	}else if(node->pre->left == node){
		node->pre->left = y;	
	}else{
		node->pre->right = y;	
	}
	y->right = node;
	node->pre = y;
	//change the hight
	node->hight = max(get_hight(node->left),
			get_hight(node->right)) + 1;
	y->hight = max(get_hight(y->left),
			get_hight(y->right)) + 1;
	
	return y;
}

/**
 * @brief balance use the functhion of get_stat
 * according the each case to let the avl tree balance
 * case1 left-left use rightrotate
 * case2 left-right use left then right rotate
 * case3 right-left use right then left rotate
 * case4 right-right use left rotate
 * @param node
 *
 * @return 
 */
void balance(Tree* tree,Node* node){
}
//the iter way 
Node* avl_search(Tree* tree, int key){
	while(tree->root != NULL && tree->root->key != key){
		if(key < tree->root->key){
			tree->root = tree->root->left;	
		}else{
			tree->root = tree->root->right;	
		}
	}
	return tree->root;
}

int avl_insert(Tree* tree, Node* node){

}
int avl_delete(Tree* tree, Node* node){
	if(tree != NULL && node != NULL)
		return -1;

	return 0;
}

int show(Node* root){
	if(root != NULL){
		printf("%d\n",root->key);
		show(root->left);
		show(root->right);
	}
}
//test main function
int main(){
	Tree* tree = avl_init_tree();	
	int ret ;
	Node* tmp = avl_init_node(12);
	Node* tmp1 = avl_init_node(9);
	Node* tmp2 = avl_init_node(8);
	ret = avl_insert(tree,tmp);
	ret = avl_insert(tree,tmp1); 
	ret = avl_insert(tree,tmp2); 
	show(tree->root);

	

	return 0;
}
