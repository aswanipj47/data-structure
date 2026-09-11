#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue()
{
  int value;
  struct node *new_node;
printf("enter value:");
scanf("%d",&value);
new_node=(struct node *)malloc(sizeof(struct node));
if(new_node ==NULL)
{
  printf("memory allocation failed\n");
  return;
}
new_node->data=value;
new_node->next=NULL;
if(front==NULL)
{
  front=new_node;
  rear=new_node;
}
else
{
rear->next=new_node;
rear=new_node;
}
  printf("enqueued element:%d\n",value);
      }
void dequeue()
{
  if(front==NULL)
  {
      printf("queue underflow\n");
      }
      else
      {
      printf("dequeued element:%d\n",front->data);
  front=front->next;
if(front ==NULL)
{
   rear=NULL;
    }
}
}

void display()
{
  struct node *curr;
  if(front==NULL)
  {
    printf("queue is empty");
    return;
  }
printf("queue element: ");
curr=front;
while(curr !=NULL)
{
  printf("%d ", curr->data);
  curr=curr->next;
}
printf("\n");
}
int main()
{
  int c;
  do
  {
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    printf("enter the choice:");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("exit\n");
        break;
default :
        printf("invalid choice\n");
        break;
    }
  }
while(c!=4);
  return 0;
}



