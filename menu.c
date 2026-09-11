#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node*next;
};
void append(struct Node **head_ref)
{
  int new_data;
  printf("Enter the data:");
  scanf("%d",&new_data);
  struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
  if(new_node==NULL)
  {
    printf("memory allocation failed \n");
    return;
  }
  new_node->data=new_data;
  new_node->next=NULL;
  if(*head_ref==NULL){
     *head_ref=new_node;
     return;
     }
     struct Node *last=*head_ref;
     while(last->next!=NULL){
     last=last->next;}
     last->next=new_node;
     }
     void print(struct Node*head){
     struct Node*temp=head;
  if(temp==NULL){
  printf("empty linkedlist");
  return;
     }
  printf("linked list:");
  while(temp !=NULL){  
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}
int main()
{
  struct Node *head =NULL;
  int c;
  do{
    printf("menu linked list\n");
    printf("1.create\n2.insert\n3.display\n4.exit\n");
    printf("enter your choice:\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
          head=NULL;
          printf("Node created\n");
          break;
      case 2:
          append(&head);
          break;
      case 3: 
          print(head);
          break;
      case 4: 
          printf("Exit\n");
          break;
      default:
          printf("invalid choice\n");
          break;
    }
 }
  while(c !=4);
  return 0;
}


