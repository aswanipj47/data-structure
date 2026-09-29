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
******Source******
*/

#include<stdio.h>
int main()
{
int stack[6],top=-1,value;
for(int i=0;i<=6;i++){
printf("Enter value:");
scanf("%d",&value);
if(top==5)
  {
    printf("overflow \n");
  }
  else
  {
    top++;
    stack[top]=value;
    printf("pushed an element into stack:%d\n",value);
  }
}

  if(top==-1)
{
  printf("stack overflow");
}
else
{
  printf("pop an element into stack:%d\n",stack[top]);
  top--;
}
if(top==-1)
{
  printf("stack is empty\n");
}
else
{
  printf("top element is:%d\n",stack[top]);
}
return 0;
  }



