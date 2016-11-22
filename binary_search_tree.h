/**
 * @file binary_search_tree.h
 * @brief 一颗搜索树既可以作为一个字典也可以作为一个优先队列
 * include the 1.Traversing Search Maxnum Minnum successor predecessor 
 *	2.insert and delete
 * @author tmd
 * @version 1.0
 * @date 2016-11-21
 */
#ifndef __BIN_TREE_H__
#define __BIN_TREE_H__
typedef struct node{
	int key;
	struct node* left;
	struct node* right;
	struct node* pre;
}Node;
typedef struct tree{
	struct node* root;
	int count;
}Tree;
//init node
Node* bin_tree_node(int key);
//init tree
int bin_tree_init(Tree* tree);
//insert
int bin_tree_insert(Tree* tree, Node* node);
//递归
Node* bin_tree_search(Node* root, int key);
//迭代
Node* bin_tree_iter_search(Node* root, int key);
//traver maxnum minnum successor predecessor
void bin_tree_inorder(Node* root);
//maxnum
Node* maxnum(Node* root);
//minnum
Node* minnum(Node* root);
//successor后继
Node* successor(Node* aim);
//predecessor前驱
Node* predece(Node* aim);

//transplant  ps:as the rotart节点的旋转
int bin_tree_transplant(Tree* tree);
//delete
int bin_tree_delete(Tree* tree, Node* node);


//free the memery
//Free(Tree* tree);







#endif //__BIN_TREE_H__
