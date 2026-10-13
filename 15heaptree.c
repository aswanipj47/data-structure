/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************

Ex No:15
Aim: Implementation  of  heap  tree  and  operations.

**********Algorithm************

Step1:Start
Step2:Insert the element into the heap.
Step3:Compare it with its parent.
Step4:If it is bigger, swap them.
Step5:Repeat until the Max Heap is correct.
Step6:To delete root, replace root with the last element.
Step7:Apply Max Heapify.
Step8:Display the heap.
Step9:Stop.

******Source code******
*/

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void insert(int arr[], int* n, int key) {
    (*n)++;
    int i = *n - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteRoot(int arr[], int* n) {
    if (*n <= 0) {
        printf("Heap underflow!\n");
        return;
    }
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
}

void display(int arr[], int n) {
    printf("Heap elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n = 0, choice, val;

    while (1) {
        printf("\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(arr, &n, val);
                break;
            case 2:
                deleteRoot(arr, &n);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
/* 
Output

1. Insert
2. Delete Root
3. Display
4. Exit
Enter choice: 1
Enter value to insert: 50

Enter choice: 1
Enter value to insert: 30

Enter choice: 1
Enter value to insert: 70

Enter choice: 3
Heap elements: 70 30 50

Enter choice: 2

Enter choice: 3
Heap elements: 50 30

Enter choice: 4
*/
