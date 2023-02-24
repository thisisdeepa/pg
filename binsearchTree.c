#include<stdio.h>
#include<stdlib.h>
typedef struct binsearchtree
{
    int data;
    struct binsearchtree *left;
    struct binsearchtree *right;
}myBST;
myBST *root=NULL;
 
myBST *createbinsearchtree(int value, myBST *ptr)
{
    if(ptr==NULL)
    {
        ptr=(myBST*)malloc(sizeof(myBST));
        ptr->data=value;
        ptr->right=NULL;
        ptr->left=NULL;
        return ptr;
    }
    else
    {
        if(value<ptr->data)
        ptr->left=createbinsearchtree(value,ptr->left);  
        else if(value>ptr->data)
        ptr->right=createbinsearchtree(value,ptr->right);
        else 
        printf("Duplicate!");
    }
    return ptr;
}

void preorder(myBST *t) //address of root node is passed in t
{
if(t!=NULL)
{
printf("\n%d",t->data); //visit the root
preorder(t->left); //preorder traversal on left subtree
preorder(t->right); //preorder traversal om right subtree
}
}

int main()
{
    int num,i,value;
    printf("Enter the number of nodes you want to create\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("Enter the data for node %d\n",i+1);
        scanf("%d",&value);
        root=createbinsearchtree(value,root);
    }
    preorder(root);
} 
