#include<stdio.h>
#include<stdlib.h>
struct node{
  int row;
  int colum;
  int value;
  struct node *next;
};
int main()
{
  int matrix[4][4]=
  {{0,0,9,0},
  {0,4,0,0},
  {2,0,0,0},
  {0,0,0,1}
  };
  struct node *head=NULL;
  struct node *temp=NULL;
  struct node *newnode;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
    if(matrix[i][j]!=0)
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->row=i;
      newnode->colum=j;
      newnode->value=matrix[i][j];
      newnode->next=NULL;
      if(head==NULL)
      {
        head=newnode;
      }
          else
          {
            temp->next=newnode;
          }
          temp=newnode;
    }
    }
  }
  printf("row column value\n");
  temp=head;
  while(temp!=NULL)
      {
      printf("%d %d %d\n",temp->row,temp->colum,temp->value);
      temp=temp->next;
      }
      return 0;
      }


