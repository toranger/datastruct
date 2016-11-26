/**
 * @file red_black_tree.c
 * @brief bst缺点 insert delete不支持  动态集合的操作，
 *		  随着每次的删除子树中心偏向左侧节点，导致成为线性搜索降低速度.
 *		  而红黑树则保证能o(lgn)去支持这两个操作
 * nature: 1.每个节点不是黑就是红色 2.根节点是黑色 3.每个叶节点都是黑色NIL 
 *		   4.如果一个节点是红色则子节点都为黑色 5.对每个节点，从该节点到其所有后代叶节
 *		   点上都包含相同数目的黑色节点（黑高相同）
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
/**
 * @brief rb_tree_insert_fixup 
 * 改变分支使整体满足红黑树性质
 * 有三种情况:1. node的叔节点是红色 2. node的叔节点是黑色且node为于父节点右侧
 * 3. node的叔节点是黑色且node为于父节点左侧
 * 情况二将父节点左旋转即可得到情况3
 * @param tree
 * @param node the insert node
 */
void  rb_tree_insert_fixup(Tree* tree, Node* node){
	while(node->pre->color == RED){//父节点为红色时需要作调整
		if(node->pre == node->pre->pre->left){//父节点在哪一测
			Node* y = node->pre->pre->right;//to rember the uncle node		
			if(y->color == RED){//case 1
				//change the father and uncle into BLACK and the grandfather is RED		
				node->pre->color = BLACK;
				y->color = BLACK;
				node->pre->pre->color = RED;
				node = node->pre->pre;
			}else{ 
				if(node == node->pre->right){
					//node on the right side(case2) can change into
					//left side(case3)
					node = node->pre;
					left_rotate(tree,node);//change into case3
				}
				//case3
				node->pre->color = BLACK;
				node->pre->pre->color = RED;
				right_rotate(tree,node->pre->pre);
			}
			
				
		}else{//父节点在右侧
		
		}

	}
	tree->root->color = BLACK;
		
}
/**
 * @brief rb_tree_insert 
 * 按照bst的插入方式将节点插入，并将插入节点置为红色，同时改变分支
 * 利用fixup函数使其满足红黑树性质
 * @param tree
 * @param node
 * @return 
 */
int rb_tree_insert(Tree* tree, Node* node){
	Node* pre = tree->nil;//rember the insert node father
	Node* tmp = tree->root;
	while(tmp != tree->nil){
		pre = tmp;	
		if(node->key < tmp->key){
			tmp = tmp->left;	
		}else{
			tmp = tmp->right;	
		}
	}
	node->pre = pre;
	if(pre == tree->nil){//node is root
		tree->root = node;	
	}else if(node->key < pre->key){//node on left
		pre->left = node;	
	}else{
		pre->right = node;	
	}
	//init node
	node->left = tree->nil;
	node->right = tree->nil;
	node->color = RED;//don't change the black high in the breach tree
	//according to the rb tree nature exchange the node loction in breach tree
	rb_tree_insert_fixup(tree,node);
	return 0;
}
int rb_tree_transplant(Tree* tree, Node* node, Node* aim){

}
int rb_tree_delete_fixup(Tree* tree, Node* node){

}
int rb_tree_delete(Tree* tree, Node* node){

}


//test main funciton
int main()
{
		
	return 0;
}

