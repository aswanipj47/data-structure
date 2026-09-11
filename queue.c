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

