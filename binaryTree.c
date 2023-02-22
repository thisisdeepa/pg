#include<stdio.h>
#include<stdlib.h>
typedef struct MyBinaryTree
{
    int data;
    struct MyBinaryTree *left;
    struct MyBinaryTree *right;
}MyBT;
 MyBT *root=NULL;

MyBT *createBt()
{
    int value;
    MyBT *ptr;
    printf("Enter the element to be inserted, -1 for no element\n");
    scanf("%d",&value);
    if(value==-1)
    return NULL;
    ptr=(MyBT*)malloc(sizeof(MyBT));
    ptr->data=value;
    printf("Enter the left child of %d\n",value);
    ptr->left=createBt();
    printf("Enter the right child of %d\n",value);
    ptr->right=createBt();

    return ptr;
}

void inorder(MyBT *t)
{
    if(t!=NULL)
    {
    inorder(t->left);
    printf("%d\t",t->data);
    inorder(t->right);
    }
}

void preorder(MyBT *t)
{
    if(t!=NULL)
    {
    printf("%d\t",t->data);
    preorder(t->left);
    preorder(t->right);
    }
}

void postorder(MyBT *t)
{
    if(t!=NULL)
    {
    postorder(t->left); 
    postorder(t->right);
    printf("%d\t",t->data);
    }
}

int search(MyBT *node,int val)
{
    if(node==NULL)
    return 0;
    if(node->data==val )
    return 1;
    int res1=search(node->left,val);
    printf("%d",res1);
    if(res1==1)
    return res1;
    int res2=search(node->right,val);
    printf("#%d",res2);

    
    return res2;
}

 void main()
 {
     root=createBt();
     printf("\nThe inorder traversal:\n");
     inorder(root);
     printf("\nThe pre order traversal:\n");
     preorder(root);
     printf("\nThe post order traversal:\n");
     postorder(root);
     printf("Enter the element to search\n");
     int key;
     scanf("%d",&key);
     int y=search(root,key);
     if(y==1)
     printf("found\n");
     else
     printf("noooo!!\n");
 }