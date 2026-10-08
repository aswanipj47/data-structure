/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:10
Aim: Implementation  of  binary  search  trees  and  perform  the    operations  on  BST.



**********Algorithm************

Step1:Start
Step2:Create an empty BST.
Step3:Enter the number of nodes and values.
Step4:Insert each value into the BST.
Step5:Display the BST using inorder traversal.
Step6:Enter a value and search it in the BST.
Step7:Enter a value and delete it from the BST.
Step8:Display the BST after deletion.
Step9:Stop.


******Source code******
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *left,*right;
};
struct node *insert(struct node *Node,int x)
{
  if(Node==NULL)
  {
    Node=malloc(sizeof(struct node));
    Node->data=x;
    Node->left=Node->right=NULL;
  }
  else if(x<Node->data)
    Node->left=insert(Node->left,x);
  else
    Node->right=insert(Node->right,x);
  return Node;
}
void search(struct node *Node,int x)
{
  if(Node ==NULL)
    printf("not found");
  else if(Node->data==x)
  printf("found");
  else if(x<Node->data)
    search(Node->left,x);
  else
    search(Node->right,x);
}
struct node *delete(struct node *Node,int x)
{
  struct node *temp;
  if(Node==NULL)
    return Node;
if(x<Node->data)
  Node->left=delete(Node->left,x);
else if(x>Node->data)
  Node->right=delete(Node->right,x);
else
{
  if(Node->left==NULL)
  {
    temp=Node->right;
    free(Node);
    return temp;
  }
  if(Node->right==NULL)
  {
    temp=Node->left;
    free(Node);
    return temp;
    }
    temp=Node->right;
    while(temp->left!=NULL)
    temp=temp->left;
    Node->data=temp->data;
    Node->right=delete(Node->right,temp->data);
    }
    return Node;
    }
void display(struct node *Node)
{
  if(Node != NULL)
  {
    display(Node->left);
    printf("%d ",Node->data);
    display(Node->right);
  }
}
int main()
{
  struct node *Node=NULL;
  int n,x;
  {
  printf("Enter no of nodes:");
  scanf("%d",&n);
  printf("Enter values:");
  for(int i=0;i<n;i++)
  {
  scanf("%d",&x);
  Node=insert(Node,x);
  }
  printf("binary search tree:");
  display(Node);
  printf("\nEnter value to search:");
  scanf("%d",&x);
  search(Node,x);
  printf("\nEnter value to delete:");
  scanf("%d", &x);
  Node=delete(Node,x);
  printf("after deletion:");
  display(Node);
  printf("\n");
  return 0;
  }
}

/* Output

   Enter no of nodes:4
Enter values:10 20 30 40
binary search tree:10 20 30 40
Enter value to search:20
found
Enter value to delete:30
after deletion:10 20 40
*/
