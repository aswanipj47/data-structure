#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
void append(struct node **head,int data)
{
  struct Node *new_node=(struct Node *)malloc(sizeof(struct Node))
  new_node->data=data;
  new_node->next=NULL;
  if(*head==NULL)
{
  *head=new_node;
  return;
}
  struct node *temp=*head;
 while(temp->next!=null)
  temp=temp->next;
  temp->next=new_node;
  }
void deletefront(struct node **head)
  if(*head==NULL)
{
  printf("list is empty");
  return;
}
struct Node *temp=*head;
*head=(*head)->next;
free(temp);
printf("first node deleted");
void deleteend(struct Node **head)
  if(*head==NULL)
{
printf("list is empty");
return;
}
if(*head->next==NULL)
{
  free(head);
  *head=NULL;
  printf("last node deleted");
  retrurn;
}
struct node*temp=*head;
while(temp->next->next!=NULL)
temp=temp->next;
free(temp->next);
temp->next=NULL;
printf("delete at end");
void deleteinbetween(struct node **head)
{
  int key;
  printf("enter delete value:");
  scanf("%d",&key);
  if(*head==NULL)
{
  printf("list is empty");
  return;
}
struct node *temp=*head;
struct node *prev=NULL;
while(temp!=NULL && temp->data=key)
{
  prev=temp;
  temp=temp->next;
}
if(temp==NULL)
{
  printf("value not found");
  return;
}
if(prev==NULL)
  *head=temp->next;
  else 
  prev->next=temp->next;
  free(temp);
  printf("node deleted");
  void display(struct Node *head)
  if(head==null)
{
  printf("list is empty");
  return;
}
while(head!=NULL)
{
  printf("%d->"head->next);
  head=head->next;
{
  printf("NULL\n");
}
int main();
{
  struct node *head=NULL;
  int c;
  append(&head,10);
  append(&head,20);
  append(&head,30);
  append(&head,40);
  do
  {
  printf("-----menu-----");
  printf("1.front\n2.end\n3.inbetween4.display\n5.exit\n");
  printf("enter your choice:");
  scanf("%d",&c);
  switch(c);
  {
    case 1:
      front(&head);
      break;
    case 2:
      end(&head);
      break;
    case 3:
      inbetween(&head);
      break;
    case 4: 
      display(head);
      break;
    case 5:
      printf("exit\n");
    default:
      printf("invalid choice.");
  }
  }
  while(c!=5)
  return 0;
}


