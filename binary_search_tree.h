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
}Node;
typedef struct tree{
	struct node* root;
	int count;
}Tree;
//init tree
int bin_tree_init(Tree* tree);
//traver maxnum minnum successor predecessor
void bin_tree_inorder(Tree* tree);
//init node
int bin_tree_node(int key);
//递归
int bin_tree_search(Tree* tree, int key);
//迭代
int bin_tree_iter_search(Tree* tree, int key);
//insert
int bin_tree_insert(Tree* tree, Node* node);
//transplant  ps:as the rotart节点的旋转
int bin_tree_transplant(Tree* tree);
//delete
int bin_tree_delete(Tree* tree, Node* node);


//free the memery
//Free(Tree* tree);







#endif //__BIN_TREE_H__
