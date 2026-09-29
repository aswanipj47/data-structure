/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:2
Aim: Implementation of queue using arrays. 
**********Algorithm************

Step1:Start
Step2:Create a queue of size 5.
Step3:Set front = -1 and rear = -1.
Step4:Enter 5 values.
Step5:If rear == 4, display Queue Overflow.
Step6:Otherwise, insert the value and increase rear.
Step7:If the queue is empty, display Queue Underflow.
Step8:Otherwise, remove the element from front and increase front.
Step9:If the queue is not empty, display the front element.
Step10:Stop.
******Source******
*/
#include<stdio.h>
int main()
 {
    int queue[5],front=-1,rear=-1,value;
    int i;
    for(i=0;i<5;i++)
{
printf("enter value:");
scanf("%d",&value);
if(rear==4)
{
  printf("queue overflow\n");
}
else
{
  if(front==-1)
    front=0;
  rear++;
  queue[rear]= value;
  printf("enqueued element:%d\n",value);
      }
      }
      if(front==-1||front>rear)
      {
      printf("queue underflow\n");
      }
      else
      {
      printf("dequeued element:%d\n",queue[front]);
  front++;
      }
if(front ==-1||front>rear)
{
    printf("queue is empty\n");
    }
else
{
  printf("front element:%d\n",queue[front]);
}
return 0;
}

