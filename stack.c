/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:1
Aim: Implementation of stack using arrays


**********Algorithm************

Step1:Start
Step2:Create stack of size 6.
Step3:Set top = -1.
Step4:Enter a value.
Step5:If top == 5, print Overflow.
Step6:Otherwise, increase top and push the value.
Step7:If stack is not empty, pop the top element.
Step8:Decrease top.
Step9:If stack is not empty, display the top element.
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

