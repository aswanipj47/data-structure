#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
};
struct node *createnode(int value)
{
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=value;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
 int main()
{
  struct node *root;
  root=createnode(10);
  root->left=createnode(20);
  root->right=createnode(30);
  root->left->left=createnode(40);
  root->left->right=createnode(50);
  printf("root=%d\n",root->data);
  printf("left child=%d\n",root->left->data);
  printf("right child=%d\n",root->right->data);
  return 0;
}


