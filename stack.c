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



