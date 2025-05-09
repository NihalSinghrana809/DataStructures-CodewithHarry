#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createNode(int data){
struct node*n;
n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->left=NULL;
n->right=NULL;
return n;
};
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
};
int isBST(struct node*root){
    static struct node*prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    return 1;
}
int main(){
struct node*p=createNode(5);
struct node*p1=createNode(3);
struct node*p2=createNode(6);
struct node*p3=createNode(1);
struct node*p4=createNode(4);
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
inorder(p);
if(isBST(p)){
    printf("\nThe Tree is BST :\n");
}
else{
    printf("\nThe Tree is not a BST:\n");
}
return 0;
}