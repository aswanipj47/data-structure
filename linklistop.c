#include<stdio.h>
#include<stdlib.h>
  struct node{
    int data;
    struct node*next;
 }*head=NULL,*temp;
int data;
void insert(){
  struct node*new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data:\n");
  scanf("%d",&data);
  new_node->data =data;
  new_node->next=NULL;
  if(head==NULL){
    head=new_node;
    return;
  }
  temp=head;
  while(temp->next!=NULL){
    temp=temp->next;}
  temp->next=new_node;
}
void delete(){
if(head==NULL){
        printf("Empty linkedlist\n");
        return;
}
else{
temp=head;
head=head->next;
free(temp);
printf("Node deleted\n");
}
}
  void display(){
    if(head==NULL){
        printf("Empty linkedlist\n");
        return;
    }
    temp=head;
    printf("Linkedlist\n");
    while(temp!=NULL){
      printf("%d->",temp->data);
      temp=temp->next;
    }
    printf("NULL\n");
      }
int main(){
        int c;
        do{
        printf("Linkedlist\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&c);
        switch(c){
                case 1:
                        insert();
                        break;
                 case 2:
                        delete();
                        break;
                 case 3:
                        display();
                        break;
                 case 4:
                        printf("Thankyou\n");
                        break;
                default:
                        printf("Invalid\n");
                        break;
        }
        }while(c!=4);
  return 0;
}

/* Output

   Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
1
Enter the data:
12
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
1
Enter the data:
45
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
1
Enter the data:
67
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
3
Linkedlist
12->45->67->NULL
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
2
Node deleted
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
3
Linkedlist
45->67->NULL
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
3
Linkedlist
45->67->NULL
Linkedlist
1.Insert
2.Delete
3.Display
4.Exit
Enter your choice:
4
Thankyou
*/
