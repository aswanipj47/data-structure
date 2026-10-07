#include<stdio.h>
int i,temp;
void heapify(int arr[],int n,int i){
        int g=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n && arr[l]>arr[g])
                g=l;
        if(r<n && arr[r]>arr[g])
                g=r;
        if(g!=i){
                temp=arr[i];
                arr[i]=arr[g];
                arr[g]=temp;
                heapify(arr,n,g);
        }
}
void heap(int arr[],int n){
for( i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
for( i=n-1;i>0;i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
        }
}
int main(){
int arr[10],n,i;
printf("Enter the no of elements:\n ");
scanf("%d",&n);
printf("Enter the elements of array:\n");
for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
heap(arr,n);
printf("After Sorting\n");
for(i=0;i<n;i++)
        printf("%d ",arr[i]);
printf("\n");
return 0;
}
/* 
Output
Enter the no of elements:
 4
Enter the elements of array:
10 5 20 15
After Sorting
5 10 15 20 
*/

