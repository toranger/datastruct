#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"binary_search_tree.h"
//init node
Node* bin_tree_node(int key){
	Node* node = (Node*)malloc(sizeof(Node));
	if(node != NULL){
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->pre = NULL;
	}else{
		return NULL;	
	}
	return node;
}

//init tree
Tree* bin_tree_init(){
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	if(tree == NULL)
		exit(1);
	tree->root = NULL;
	tree->count = 0;
	return tree;
}

//insert
int bin_tree_insert(Tree* tree,Node* node){
	if(tree == NULL || node == NULL)
		return -1;
	int key = node->key;
	Node* pre = NULL;
	Node* tmp = tree->root;
	//to find the node father node pre
	while(tmp != NULL){
		pre = tmp;			
		if(key < tmp->key){
			tmp = tmp->left;
		}else{
			tmp = tmp->right;	
		}
	}
	node->pre = pre;
	//judge node in which side of pre node
	if(pre == NULL){
		tree->root = node;	
	}else if(node->key < pre->key){
		pre->left = node;	
	}else{
		pre->right = node;	
	}
	return 0;
}
//递归
Node* bin_tree_search(Node* root,int key){
	if(root == NULL || root->key == key)
		return root;
	if(key < root->key){
		return bin_tree_search(root->left,key);	
	}else{
		return bin_tree_search(root->right,key);
	}
}
//迭代
Node* bin_tree_iter_search(Node* root, int key){
	while(root != NULL && root->key != key){
		if(key < root->key){
			root = root->left;	
		}else{
			root = root->right;	
		}	
	}
	return root;
}
//traver遍历 inorder中序 其他类似思路
void bin_tree_inorder(Node* root){
	if(root != NULL){
		bin_tree_inorder(root->left);	
		printf("%d\n",root->key);
		bin_tree_inorder(root->right);	
	}
}
//max
Node* maxnum(Node* root){
	while(root->right != NULL)
		root = root->right;
	return root;
}
//min
Node* minnum(Node* root){
	while(root->left != NULL)
		root = root->left;
	return root;
}
//successor 
//whether has the right son tree
//whether is the father's right node
Node* successor(Node* aim){
	if(aim->right != NULL){
		//有右子树则aim的后继是右子树中最小的节点
		return minnum(aim->right);
	}	
	//判断是否是父亲节点的右节点不是则为父节点
	Node* tmp = aim->pre;
	while(tmp != NULL && (tmp->right = aim)){
		aim = tmp;	
		tmp = tmp->pre;
	}
	return tmp;
}
//predece
Node* predece(Node* aim){
	if(aim->left != NULL){
		return maxnum(aim->left);	
	}
	Node* tmp = aim->pre;
	while(tmp != NULL && (tmp->left = aim)){
		aim = tmp;	
		tmp = tmp->pre;
	}
	return tmp;
}
//search min max succ predece  O(h)  h = lgn 树高
//transplant use aim to change node as the son tree root node
void bin_tree_transplant(Tree* tree,Node* node,Node* aim){
	if(node->pre == NULL){//node is root
		tree->root = aim;
	}else if(node == node->pre->left){//node in left side
		node->pre->left = aim;		
	}else{
		node->pre->right = aim;//right side	
	}
	if(aim != NULL)
		aim->pre = node->pre;
	return ;
}
//delete
int bin_tree_delete(Tree* tree, Node* node){
	if(tree == NULL)
		return -1;
	if(node->left == NULL){
		//stright	
		bin_tree_transplant(tree,node,node->right);
	}else if(node->right == NULL){
		bin_tree_transplant(tree,node,node->left);	
	}else{//the node want to delete have two side 
		Node* aim = successor(node);//the aim is the minest num in the right side 	
		if(aim->pre != node){
			//is not the son of node	
			//exchange the aim with aim right side
			//ps: aim does not have left side
			bin_tree_transplant(tree,aim,aim->right);		
			aim->right = node->right;
			aim->right->pre = aim;
			
		}	
		//no matter what it has to change the aim and node
		bin_tree_transplant(tree,node,aim);
		aim->left = node->left;
		aim->left->pre = aim;
	}
	return 0;
}
//Free(Tree* tree){}

//test main function
int main()
{
	
	


	return 0;
}

