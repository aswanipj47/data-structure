#include<stdio.h>
#include<stdlib.h>
  struct Node
   {
     int data;
     struct Node*next;
   };
   struct Node*top=NULL;
   void push()
   {
    struct Node*new_node;
    int data;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    if(new_node==NULL)
  {
    printf("stack overflow");
    return;
  }
  printf("enter the data:");
  scanf("%d",&data);
  new_node->data=data;
  new_node->next=top;
  top=new_node;
  printf("pushed data=%d\n",data);
  }
  void pop()
  {
    if(top==NULL)
    {
      printf("stack underflow");
     return;
    }
    printf("stack pop into data=%d\n",top->data);
    top=top->next;
  }
  void peek()
      {
        if(top==NULL)
        {
          printf("stack is empty");
          return;
        }
      printf("top data=%d\n",top->data);
      }
  int main()
  {
   int c;
    do{
      printf("1.push\n2.pop\n3.peep\n4.exit\n");
      printf("enter the choice\n");
      scanf("%d",&c);
      switch(c)
  {
    case 1:
      push();
           break;
   case 2:
          pop();
           break;
    case 3:
           peek();
           break;
    case 4:
           printf("exit\n");
    default:
           printf("invalid choice\n");
  }
  }
  while(c!=4);
  return 0;
  }
            
