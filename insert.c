#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node*next;
};
void append(struct Node **head_ref)
{
  int data;
  printf("Enter the data:");
  scanf("%d",&data);
  struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
  new_node->data=data;
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
     void insertfront(struct Node**head_ref){
       int data;
     struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
     printf("enter the data:\n");
     scanf("%d",&data);
     new_node->data=data;
     new_node->next=*head_ref;
     *head_ref=new_node;
     printf("Insertion to front\n");
     }
      void insertinbetween(struct Node*head){
      int key,data;
      if(head==NULL)
      {
        printf("list is empty\n");
        return;
      }
      printf("enter the key after which to insert:");
      scanf("%d",&key);
      while(head !=NULL && head->data!=key)
        head=head->next;
      if(head==NULL)
      {
        printf("value not found\n");
        return;
      }
      struct Node*new_node=(struct Node *)malloc(sizeof(struct Node));
      printf("enter data:");
      scanf("%d",&data);
      new_node->data=data;
      new_node->next=head->next;
      head->next=new_node;
     }
      void display(struct Node *head)
      {
        if(head==NULL)
        {
          printf("list is empty\n");
          return;
        }
        printf("linked list:");
        while(head!=NULL){
          printf("%d->",head->data);
          head=head->next;
        }
        printf("NULL\n");
      }

int main()
{
  struct Node *head =NULL;
  int c;
  do{
    printf("menu linked list\n");
    printf("1.Insert\n2.end\n3.inbetween\n4.display\n5.exit\n");
    printf("enter your choice:\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
          insertfront(&head);
          break;
      case 2:
          append(&head);
          break;
      case 3: 
          insertinbetween(head);
          break;
      case 4: 
          display(head);
          break;
      case 5:
          printf("exit\n");
          break;
      default:
          printf("invalid choice\n");
          break;
    }
 }
  while(c !=5);
  return 0;
}


