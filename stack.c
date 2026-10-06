/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:1
Aim: Implementation of stack using arrays


**********Algorithm************

Step1:Start
Step2:Set top = -1.
Step3:Read array size.
Step4:Display menu.
Step5:Choose Push, Pop, Peek or Exit.
Step6:Push: If stack is full → Overflow, otherwise insert element.
Step7:Pop: If stack is empty → Underflow, otherwise remove top element.
Step8:Peek: Display the top element.
Step9:Repeat until Exit.
Step10:Stop.


******Source code******
*/


#include<stdio.h>
int s[10],n,top=-1;
void push(int n){
  if(top==n-1){
    printf("overflow\n");
    return ;
}
else{
  top+=1;
  printf("enter the data\n");
  scanf("%d",&s[top]);
}
}
void pop(){
  if(top==-1){
    printf("underflow\n");
    return;}
  else{
    printf("element removed\n");
    top-=1;}
}
void peek(){
  if(top==-1){
    printf("Stack empty\n");
    return;
}
  else
    printf("top=%d\n",s[top]);
}
int main(){
  int c;
  printf("Enter size of array\n");
  scanf("%d",&n);
  do{
        printf("1.push\n2.pop\n3.peek\n4.exit\n");
        scanf("%d",&c);
        switch(c){
          case 1:
                push(n);
                break;
          case 2:
                pop();
                break;
          case 3:
                peek();
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

