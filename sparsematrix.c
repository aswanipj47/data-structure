#include<stdio.h>
int main()
{
int sparsematrix[3][4]=
{
{0, 0, 3, 0},
{0, 5, 0, 0},
{7, 0, 0, 0}
};
int size=0;
for(int i=0;i<3;i++)
  for(int j=0;j<4;j++)
    if(sparsematrix[i][j] !=0)
    size++;
int compactmatrix[size][3];
int k=0;
  for(int i=0;i<3;i++)
    for(int j=0;j<4;j++)
     if(sparsematrix[i][j]!=0)
     {
  compactmatrix [k][0]=i;
  compactmatrix [k][1]=j;
  compactmatrix [k][2]=sparsematrix[i][j];
  k++;
    }
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<3;j++)
      printf("%d ",compactmatrix[i][j]);
    printf("\n");
  }
  return 0;
}
  
