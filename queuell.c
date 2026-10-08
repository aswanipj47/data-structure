/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:6
Aim: Implementation of Queue using Linkedlist. 


***********Algorithm************

Step1:Start
Step2:Initialize front = NULL and rear = NULL.
Step3:Display the menu: Enqueue, Dequeue, Display, Exit.
Step4:Read the user's choice.
Step5:If Enqueue:Create a new node.Insert the element at the rear.
Step6:If Dequeue:Check whether the queue is empty.If empty, display Queue Underflow.Otherwise, delete the element from the front.
Step7:If Display:Check whether the queue is empty.If not empty, display all elements from front to rear.
Step8:If Exit, terminate the program.
Step9:Repeat steps 3–8 until the user chooses Exit.
Step10:Stop.


******Source code******
*/


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

/*Output

  1.enqueue
2.dequeue
3.display
4.exit
enter the choice:1
enter value:10
enqueued element:10
1.enqueue
2.dequeue
3.display
4.exit
enter the choice:1
enter value:20
enqueued element:20
1.enqueue
2.dequeue
3.display
4.exit
enter the choice:1
enter value:30
enqueued element:30
1.enqueue
2.dequeue
3.display
4.exit
enter the choice:3
queue element: 10 20 30
1.enqueue
2.dequeue
3.display
4.exit
enter the choice:2
dequeued element:10
1.enqueue
2.dequeue
3.display
4.exit
enter the choice:3
queue element: 20 30
1.enqueue
2.dequeue
3.display
4.exit
enter the choice:4
exit
*/

