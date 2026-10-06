/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:9
Aim: Implementation of circular Linkedlist. 


**********Algorithm************

Step1:Start
Step2:Set front = -1 and rear = -1.
Step3:Display the menu.
Step4:Read the choice.
Step5:If Enqueue, insert an element into the queue.
Step6:If Dequeue, remove an element from the queue. 
Step7:If display, display the queue elements. 
Step8:If exit, stop the program. 
Step9:Repeat until Exit. 
Step10:Stop.


******Source code******
*/


#include<stdio.h>
#define SIZE 5
int q[5],rear=-1,front=-1,i,c,ele;
void enqueue(){
  int ele;
  if((rear+1)%SIZE==front){
    printf("Queue Full\n");
    return ;
  }
  else{
    printf("enter the data\n");
    scanf("%d",&ele);
    if(front==-1 &&rear ==-1)
      front=rear=0;
    else
      rear++;
    if(rear==SIZE)
      rear=0;
    q[rear]=ele;
    printf("Inserted\n");
  }
}
void dequeue(){
  if(front==-1 && rear==-1){
    printf("underflow\n");
    return;
  }
  else{
    printf("element removed %d\n",q[front++]);
    if((front-1)%SIZE==rear)
      front=rear=-1;
    if(front==SIZE)
      front=0;
}
}
void display(){
  if(rear==-1 &&  front==-1)
    printf("Queue Empty\n");
  else if(rear>front){
    for(int i=front;i<=rear;i++)
      printf("%d\t",q[i]);
  }
  else{
    for(i=front;i<=SIZE-1;i++)
      printf("%d",q[i]);
    for(i=0;i<=rear;i++)
      printf("%d",q[i]);
  }
}
int main(){
 int c;
  do{
        printf("\nCircularQueue using Array\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("Enter your choice\n");
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

/* Output

  CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
1
enter the data
10
Inserted

CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
1
enter the data
20
Inserted

CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
1
enter the data
30
Inserted

CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
3
10	20	30	
CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
2
element removed 10

CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
3
20	30	
CircularQueue using Array
1.enqueue
2.dequeue
3.display
4.exit
Enter your choice
4
exit
*/
