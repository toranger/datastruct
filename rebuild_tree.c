#include <stdio.h>
#include <stdlib.h>
struct node{
        int num;
        struct node* pleft;
        struct node* pright;
};
struct node* rebuild_process(int* pre_start, int* pre_end, int* in_start, int* in_end){
        int value = pre_start[0];
        struct node* root = (struct node*)malloc(sizeof(struct node));
        root->num = value;
        root->pleft = root->pright = NULL;
        //judge whether only one node
        if(pre_start == pre_end){
                if(in_start == in_end && *pre_start == *in_start)
                        return root;
                else
                        return NULL;
        }


        //already know the root to find index in the inorder arr
        int* root_inoder = in_start;
        while(root_inoder <= in_end && *root_inorder != value){
                ++root_inorder;
        }
        if(root_inorder == in_end && *root_inorder != value)
                return NULL;

        //sperate the left and right child trees

}
struct node* rebuild(int* preorder, int* inorder, int len){
        if(preorder == NULL || inorfer == NULL || len <=0)
                return -1;
        return rebuild_process(preorder,preorder+len-1,inorder,inorder+len-1);

}

int main(){
        






        return 0;
}
