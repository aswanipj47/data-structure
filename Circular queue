#include <stdio.h>
#define SIZE 5
int main()
{
    int que[20],front=-1,rear=-1,i,ch,ele;
    do{
        printf("\nChoose from the menu:");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: if((rear+1)%SIZE==front)
   printf("\nQueue is full");
      else{
   printf("\nEnter the element you want to insert:");
                        scanf("%d",&ele);
                        if(rear==-1 && front==-1)
                rear=front=0;
               else
                rear++;
               if(rear==SIZE )
                rear=0;
           que[rear]=ele;
                        printf("%d is inserted at the rear of the queue",ele);
                    }
                    break;
            case 2: if(rear==-1 && front==-1)
                        printf("\nQueue Empty");
                    else{
                        printf("\nThe element removed from the queue is %d",que[front++]);
                        if((front-1)%SIZE==rear)
       front=rear=-1;
   if (front==SIZE)
    front=0;
      }
                    break;
            case 3: if(rear==-1 && front==-1)
                        printf("\nThe queue is empty");
                    else if(rear>front){
                        printf("\nThe queue contains:\n");
                        for(i=front;i<=rear;i++)
                            printf("%d\t",que[i]);
                    }
             else {
   printf("\nThe queue contains:\n", );
                        for(i=front;i<=SIZE-1;i++)
                            printf("%d\t",que[i]);
   for(i=0;i<=rear;i++)
                            printf("%d\t",que[i]);
     }
    break;
            case 4:printf("\nThank you");
                    break;
            default:printf("\nWrong entry, please choose from the menu once again");
        }
    }while(ch!=4);
}
