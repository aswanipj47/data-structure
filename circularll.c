/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:8
Aim: Implementation of circular linkedlist


**********Algorithm************

Step1:Start
Step2:Create a circular linked list by inserting nodes at the end.
Step3:If the list is empty, make the new node as head.
Step4:Otherwise, find the last node and connect the new node to head.
Step5:Display all nodes until temp reaches head again.
Step6:To delete a node, search for the given value.
Step7:If the value is found, adjust the links and delete the node.
Step8:Display the list after deletion.
Step9:Stop


******Source code******
*/
  #include <stdio.h>
  #include <stdlib.h>
  struct Node {
      int data;
      struct Node *next;
  };
  struct Node *head = NULL;
  void insertEnd(int value) {
      struct Node *newNode = malloc(sizeof(struct Node));
      if (newNode == NULL) {
          printf("Memory allocation failed\n");
          return;
      }
    newNode->data = value;
      if (head == NULL) {
          head = newNode;
          newNode->next = head;
          return;
      }
      struct Node *temp = head;
   while (temp->next != head) {
          temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
  }
  void display() {
      if (head == NULL) {
          printf("List is empty\n");
          return;
      }
      struct Node *temp = head;
    do {
          printf("%d -> ", temp->data);
          temp = temp->next;
      } while (temp != head);
      printf("(head)\n");
  }
  void deleteNode(int value) {
      if (head == NULL) {
          printf("List is empty\n");
          return;
      }
      struct Node *current = head;
      struct Node *previous = NULL;
      do {
          if (current->data == value)
              break;
          previous = current;
        current = current->next;
      } while (current != head);
     if (current->data != value) {
          printf("Value not found\n");
          return;
      }
      if (current == head && head->next == head) {
          free(head);
          head = NULL;
          return;
      }
      if (current == head) {
          struct Node *last = head;
          while (last->next != head) {
              last = last->next;
          }
          head = head->next;
          last->next = head;
          free(current);
      }
    else {
      previous->next = current->next;
        free(current);
    }
}
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
  insertEnd(40);
    printf("Circular Linked List:\n");
    display();
    deleteNode(20);
    printf("After deleting 20:\n");
    display();
    return 0;
}
/*
   ********** OUTPUT *********

 Circular Linked List:
 10 -> 20 -> 30 -> 40 -> (head)
 After deleting 20:
 10 -> 30 -> 40 -> (head)
*/
       
