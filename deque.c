/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:17
Aim: Implementation  of  Deque (double ended  queue).


**********Algorithm************

Step1:Start
Step2:Create an empty deque.
Step3:Insert Front: Add a node at the front.
Step4:Insert Rear: Add a node at the rear.
Step5:Delete Front: Remove the front node.
Step6:Delete Rear: Remove the rear node.
Step7:Get Front: Display the front element.
Step8:Get Rear: Display the rear element.
Step9:Get Size: Display the number of elements.
Step10:Check Empty: Check whether deque is empty.
Step11:Erase: Delete all elements.
Step12:Repeat operations until Exit.
Step13:Stop.


******Source code******
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} n;

typedef struct myDeque {
    n *front, *rear;
    int size;
} dq;

dq* createMyDeque() {
    dq* mq = (dq*)malloc(sizeof(dq));
    mq->front = mq->rear = NULL;
    mq->size = 0;
    return mq;
}

int isEmpty(dq* mq) { 
    return mq->front == NULL; 
}

int getSize(dq* mq) { 
    return mq->size; 
}

void insertFront(dq* mq, int data) {
    n* newNode = (n*)malloc(sizeof(n));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = mq->front;

    if (isEmpty(mq)) {
        mq->front = mq->rear = newNode;
    } else {
        mq->front->prev = newNode;
        mq->front = newNode;
    }
    mq->size++;
    printf("Inserted %d at the front.\n", data);
}

void insertRear(dq* mq, int data) {
    n* nn = (n*)malloc(sizeof(n));
    nn->data = data;
    nn->next = NULL;

    if (isEmpty(mq)) {
        nn->prev = NULL;
        mq->front = mq->rear = nn;
    } else {
        nn->prev = mq->rear;
        mq->rear->next = nn;
        mq->rear = nn;
    }
    mq->size++;
    printf("Inserted %d at the rear.\n", data);
}

void deleteFront(dq* mq) {
    if (isEmpty(mq)) {
        printf("UnderFlow: Deque is empty!\n");
        return;
    }
    n* temp = mq->front;
    mq->front = mq->front->next;
    
    if (mq->front) {
        mq->front->prev = NULL;
    } else {
        mq->rear = NULL;
    }
    
    printf("Deleted front element: %d\n", temp->data);
    free(temp);
    mq->size--;
}

void deleteRear(dq* mq) {
    if (isEmpty(mq)) {
        printf("UnderFlow: Deque is empty!\n");
        return;
    }
    n* temp = mq->rear;
    mq->rear = mq->rear->prev;
    
    if (mq->rear) {
        mq->rear->next = NULL;
    } else {
        mq->front = NULL;
    }
    
    printf("Deleted rear element: %d\n", temp->data);
    free(temp);
    mq->size--;
}

int getFront(dq* mq) { 
    return isEmpty(mq) ? -1 : mq->front->data; 
}

int getRear(dq* mq) { 
    return isEmpty(mq) ? -1 : mq->rear->data; 
}

int main() {
    dq* mq = createMyDeque();
    int choice, data;

    do {
        printf("\n--- Deque Operations Menu ---\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Get Front Element\n6. Get Rear Element\n7. Get Current Size\n8. Check if Empty\n9. Erase Deque\n10. Exit\n");
        printf("Enter your choice (1-10): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter integer value to insert at front: ");
                scanf("%d", &data);
                insertFront(mq, data);
                break;
            case 2:
                printf("Enter integer value to insert at rear: ");
                scanf("%d", &data);
                insertRear(mq, data);
                break;
            case 3:
                deleteFront(mq);
                break;
            case 4:
                deleteRear(mq);
                break;
            case 5:
                data = getFront(mq);
                if (data == -1 && isEmpty(mq))
                    printf("Deque is empty!\n");
                else
                    printf("Front element: %d\n", data);
                break;
            case 6:
                data = getRear(mq);
                if (data == -1 && isEmpty(mq))
                    printf("Deque is empty!\n");
                else
                    printf("Rear element: %d\n", data);
                break;
            case 7:
                printf("Current size of deque: %d\n", getSize(mq));
                break;
            case 8:
                if (isEmpty(mq))
                    printf("Yes, the deque is empty.\n");
                else
                    printf("No, the deque is not empty.\n");
                break;
            case 9:
                while (!isEmpty(mq)) {
                    deleteFront(mq);
                }
                printf("Deque erased successfully.\n");
                break;
            case 10:
                printf("Exiting program. All memory freed.\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 10.\n");
        }
    } while (choice != 10);

    return 0;
}
/* Output
--- Deque Operations Menu ---
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Get Front Element
6. Get Rear Element
7. Get Current Size
8. Check if Empty
9. Erase Deque
10. Exit

Enter your choice (1-10): 1
Enter integer value to insert at front: 10
Inserted 10 at the front.

Enter your choice (1-10): 2
Enter integer value to insert at rear: 20
Inserted 20 at the rear.

Enter your choice (1-10): 5
Front element: 10

Enter your choice (1-10): 6
Rear element: 20

Enter your choice (1-10): 7
Current size of deque: 2

Enter your choice (1-10): 3
Deleted front element: 10

Enter your choice (1-10): 4
Deleted rear element: 20

Enter your choice (1-10): 8
Yes, the deque is empty.

Enter your choice (1-10): 10
Exiting program. All memory freed.
*/
