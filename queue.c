/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:2
Aim: Implementation of queue using arrays. 


**********Algorithm************

Step1:Start
Step2:Set front = -1 and rear = -1.
Step3:Display the menu.
Step4:Choose Enqueue, Dequeue, Display or Exit.
Step5:Enqueue: If queue is full → Overflow, otherwise insert the element.
Step6:Dequeue: If queue is empty → Underflow, otherwise remove the front element.
Step7:Display: Display all queue elements.
Step8:Repeat until Exit.
Step9:Stop.


******Source code******
*/


#include<stdio.h>
#define SIZE 5
int q[5],rear=-1,front=-1;
void enqueue(){
  int data;
  if(rear==SIZE-1){
    printf("overflow\n");
    return ;
  }
  else{
    printf("enter the data\n");
    scanf("%d",&data);
    if(front==-1&&rear==-1)
      front++;
    rear++;
    q[rear]=data;
  }
}
void dequeue(){
  if(front==-1 && rear==-1){
    printf("underflow\n");
    return;
  }
  else{
    printf("element removed %d\n",q[front++]);
    if(front>rear){
      front=-1;
      rear=-1;
    }
  }
}
void display(){
  if(rear==-1)
    printf("Queue Empty\n");
  else{
    for(int i=front;i<=rear;i++)
      printf("%d\t",q[i]);
  }
}
int main(){
  int c;

  do{
        printf("\nQueue Array\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&c);
        switch(c){
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
          default:
                printf("invalid");
                break;
        }
  }while(c!=4);
return 0;
}

