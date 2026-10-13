/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************

Ex No:20
Aim: Implementation  of  hashing  using  separate  chaining.   

**********Algorithm************

Step1:Start
Step2:Initialize all hash table positions as NULL.
Step3:Read the value.
Step4:Find index using: index = value % 10
Step5:Create a new node.
Step6:If the index is empty, insert the node.
Step7:Otherwise, add the node at the end of the linked list.
Step8:For display, visit each index and print the values.
Step9:If choice is 3, exit.
Step10:Stop.

******Source code******
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

void initHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashKey(int key) {
    return key % TABLE_SIZE;
}

void insertHash(int key) {
    int index = hashKey(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at index %d\n", key, index);
}

void displayHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initHash();
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertHash(val);
                break;
            case 2:
                displayHash();
                break;
            case 3:
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
2. Display
3. Exit
Enter choice: 1
Enter value to insert: 25
Inserted 25 at index 5

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value to insert: 15
Inserted 15 at index 5

1. Insert
2. Display
3. Exit
Enter choice: 1
Enter value to insert: 22
Inserted 22 at index 2

1. Insert
2. Display
3. Exit
Enter choice: 2

Index 0: NULL
Index 1: NULL
Index 2: 22 -> NULL
Index 3: NULL
Index 4: NULL
Index 5: 25 -> 15 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

1. Insert
2. Display
3. Exit
Enter choice: 3
*/
