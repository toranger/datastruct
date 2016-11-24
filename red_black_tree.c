/**
 * @file red_black_tree.c
 * @brief bst缺点 insert delete不支持  动态集合的操作，
 *		  随着每次的删除子树中心偏向左侧节点，导致成为线性搜索降低速度.
 *		  而红黑树则保证能o(lgn)去支持这两个操作
 * @author tmd
 * @version 1.0
 * @date 2016-11-24
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"red_black_tree.h"
//init node
Node* rb_node_init(int key,int color){
	Node* node = (Node*)malloc(sizeof(Node));
	if(node != NULL){
		node->key = key;	
		node->color = color;
		return node;
	}
	return NULL;
}
//init tree
Tree* rb_tree_init(){
	Tree* tree = (Tree*)malloc(sizeof(Tree));	
	if(tree != NULL){
		tree->root = NULL;
		//nil node
		Node* node = rb_node_init(0,BLACK);
		if(node != NULL){
			//the nil node does not care left,key,right 
			node->left = NULL;					
			node->right = NULL;
			//when insert node the root node pre is the nil node			
			tree->nil = node;
		}else{
			exit(1);	
		}
	}
	exit(1);
}
//left_rotate
void left_rotate(Tree* tree, Node* node){
	Node* y = node->right;	
	node->right = y->left;
	//y left whether null
	if(y->left != tree->nil){//have the left side
		y->left->pre = node;	
	}
	y->pre = node->pre;
	//which side node in nodefather
	if(node->pre == tree->nil){
		tree->root = y;
	}else if(node->pre->left == node){
		node->pre->left = y;			
	}else{
		node->pre->right = y;	
	} 
	//y and node
	y->left = node;
	node->pre = y;
	return ;
}
//right_rotate is symmetry to the left_rotate
void right_rotate(Tree* tree, Node* node){
	Node* y = node->left;
	node->left = y->right;
	if(y->right != tree->nil){
		y->right->pre = node;	
	}
	y->pre = node->pre;
	if(node->pre == tree->nil){
		tree->root = y;	
	}else if(node->pre->left == node){
		node->pre->left = y;	
	}else{
		node->pre->right = y;	
	}
	y->right = node;
	node->pre = y;
	return ;
}


//test main funciton
int main()
{
		
	return 0;
}

