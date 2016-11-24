#ifndef __RED_BLACK__
#define __RED_BLACK__
enum{RED=0,BLACK=1};
typedef struct node{
	int key;	
	int color;
	struct node* pre;
	struct node* left;
	struct node* right;
}Node;
typedef struct tree{
	struct node* root;	
	//界外节点 every leaves node left ,right side and the root node point to the nil
	struct node* nil;
}Tree;
//init rb_tree
Tree* rb_tree_init();
//init node 
Node* rb_node_init(int key,int color);
//rotate旋转
//left
void left_rotate(Tree* tree, Node* node);
void right_rotate(Tree* tree, Node* node);
//insert fixup
int rb_tree_insert_fixup(Tree* tree, Node* node);
//insert
int rb_tree_insert(Tree* tree, Node* node); 




#endif