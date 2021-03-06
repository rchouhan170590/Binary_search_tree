#include<stdio.h>
#include<stdlib.h>
struct BST
    {
        int data;
        struct BST *left ;
        struct BST *right;
    };
struct BST* GetNode(int );
struct BST* Push(int,struct BST * );
int isCheckBST(struct BST * ,int ,int );
int height(struct BST*);
int searchKey(struct BST * ,int)
int main()
{
    
    
    struct BST *head=NULL;
    int value;
    // scan value and push it in BST.
    
    return 0;
}
struct BST* GetNode(int value)
{
    struct BST * temp;
    temp =(struct BST*)malloc(sizeof(struct BST));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
//Push operation always Push value in such mammer that it remain binary tree.
struct BST* Push(int value,struct BST * run)
{
    
    if(run==NULL)
      return GetNode(value);
    else if(value<run->data)
      run->left=Push(value,run->left);
    else
      run->right=Push(value,run->right);
}
// check whether give tree is BST or no. ( checking this structure is useless because this is always BST. )
int isCheckBST(struct BST * run,int min,int max)
{
    if(run==NULL)
       return 1;
    int value=run->data;
    if((value<=max)&&(value>=min))
        return ((isCheckBST(run->left,min,value))&&(isCheckBST(run->right,value,max)));
    else
        return 0;
}
// find the maximum height of BST.
int height(struct BST* run)
{
    if(run==NULL)
      return -1;
    int leftheight=1+height(run->left);
    int rightheight=1+height(run->right);
    return ((leftheight>rightheight?leftheight:rightheight));
}
// search the key in binary tree. return 0 if key is not present else return 1;
int searchKey(struct BST * run,int key)
{
    if(run==NULL)
      return 0;
    if(run->data==key)
      return 1;
    else
      return ((run->data>key)?searchKey(run->left,key):searchKey(run->right,key));
}
