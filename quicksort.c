/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:11
Aim: Implementation  of  quick  sort.


**********Algorithm************

Step1:Start
Step2:Choose the last element as pivot.
Step3:Compare each element with the pivot.
Step4:Put smaller elements on the left of pivot.
Step5:Put larger elements on the right of pivot.
Step6:Repeat the same process for the left and right parts.
Step7:Stop when the array is sorted.
Step8:Stop.


******Source code******
*/
#include <stdio.h>
void swap(int* a, int* b);
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
     int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

/* Output
1 5 7 8 9 10
*/
