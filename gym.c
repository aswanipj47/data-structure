#include<stdio.h>
#define max 50
struct member
{
int m_id;
char name[50];
float weight;
int days;
};
int main()
{
  struct member m[max];
  int count=0,choice,j,i;
  struct member temp;
  while(1)
  {
    printf("\n-----gym member tracker----\n");
    printf("\n1.add member\n");
    printf("\n2.display all member\n");
    printf("\n3.filter inactive members\n");
    printf("\n4.exit\n");
    printf("enter the choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
case 1:if (count<max)
      {
        printf("enter the m_id:");
scanf("%d",&m[count].m_id);
printf("enter the name:");
scanf("%s",m[count].name);
printf("enter the weight:");
scanf("%f",&m[count].weight);
printf("enter the days since last workout:");
scanf("%d",&m[count].days);
count++;
      }
      else
      {
        printf("member limit reached");
      }
      break;
      case 2:
      for(i=0;i<count-1;i++)
      {
        for(j=i+1;j<count;j++)
        {
          if (m[i].days<m[j].days)
          {
            temp=m[i];
            m[i]=m[j];
            m[j]=temp;
          }
        }
        }
        for(i=0;i<count;i++)
        {
        printf("\n m_id:%d",m[i].m_id);
        printf("\n name:%s",m[i].name);
        printf("\n weight:%f",m[i].weight);
        printf("\n days:%d",m[i].days);
      }
      break;
      case 3: 
      for(i=0;i<count-1;i++)
      {
        for(j=i+1;j<count;j++)
        {
          if (m[i].days<m[j].days)
          {
            temp=m[j];
            m[i]=m[j];
            m[j]=temp;
          }
        }
      }
      printf("\n inactive members:\n");
              for(i=0;i<count;i++)
              {
                if(m[i].days>7)
                {
               printf("\n m_id:%d",m[i].m_id);
               printf("\n name:%s",m[i].name);
               printf("\n weight:%f",m[i].weight);
               printf("\n days:%d",m[i].days);
                }
              }
              break;
      case 4: return 0;
      default: printf("invalid choice");
    }
  }
}



 

