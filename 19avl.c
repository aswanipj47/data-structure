/* Name:Aswani p.j
   Roll No :CS05
   Date :05-10-2026
*******************************

Ex No:19
Aim: Implementation of   AVL  tree (balanced  tree).

**********Algorithm************

Step1:Start
Step2:Insert the value into the AVL tree.
Step3:Check the balance of the tree.
Step4:If unbalanced, perform the required rotation.
Step5:Search for a key if needed.
Step6:Display the tree using inorder, preorder, or postorder.
Step7:Repeat until Exit.
Step8:Stop.

******Source code******
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* l;
    int d;
    struct Node* r;
    int height;
} n;

n* h = NULL;

int height(n* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

n* create(int d) {
    n* nn = (n*)malloc(sizeof(n));
    nn->d = d;
    nn->l = NULL;
    nn->r = NULL;
    nn->height = 1;
    return nn;
}

n* rightRotate(n* y) {
    n* x = y->l;
    n* T2 = x->r;

    x->r = y;
    y->l = T2;

    y->height = maxVal(height(y->l), height(y->r)) + 1;
    x->height = maxVal(height(x->l), height(x->r)) + 1;

    return x;
}

n* leftRotate(n* x) {
    n* y = x->r;
    n* T2 = y->l;

    y->l = x;
    x->r = T2;

    x->height = maxVal(height(x->l), height(x->r)) + 1;
    y->height = maxVal(height(y->l), height(y->r)) + 1;

    return y;
}

int getBalance(n* node) {
    if (node == NULL)
        return 0;
    return height(node->l) - height(node->r);
}

n* ins(n* node, int d) {
    if (node == NULL)
        return create(d);

    if (d < node->d)
        node->l = ins(node->l, d);
    else if (d > node->d)
        node->r = ins(node->r, d);
    else
        return node;

    node->height = 1 + maxVal(height(node->l), height(node->r));

    int balance = getBalance(node);

  
    if (balance > 1 && d < node->l->d)
        return rightRotate(node);

  
    if (balance < -1 && d > node->r->d)
        return leftRotate(node);

  
    if (balance > 1 && d > node->l->d) {
        node->l = leftRotate(node->l);
        return rightRotate(node);
    }

    
    if (balance < -1 && d < node->r->d) {
        node->r = rightRotate(node->r);
        return leftRotate(node);
    }

    return node;
}

void ser(n* root, int k) {
    if (root == NULL) {
        printf("\nKey is not found");
        return;
    }
    if (k == root->d) {
        printf("\nKey is found");
    } else if (k < root->d) {
        ser(root->l, k);
    } else {
        ser(root->r, k);
    }
}

void inorder(n* root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->d);
        inorder(root->r);
    }
}

void preorder(n* root) {
    if (root != NULL) {
        printf("%d ", root->d);
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(n* root) {
    if (root != NULL) {
        postorder(root->l);
        postorder(root->r);
        printf("%d ", root->d);
    }
}

int main() {
    int ch, data, key;
    
    while(1) {
        printf("\n\n==== AVL Tree Menu =====\n");
        printf("1. Insertion (Auto-Balancing via Rotations)\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &ch) != 1) break;
        
        switch(ch) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d", &data);
                h = ins(h, data); 
                printf("Inserted and balanced successfully.\n");
                break;
            case 2:
                printf("\nEnter key: ");
                scanf("%d", &key);
                ser(h, key);
                break;
            case 3:
                printf("\nInorder Traversal: ");
                inorder(h);
                printf("\n");
                break;
            case 4:
                printf("\nPreorder Traversal: ");
                preorder(h);
                printf("\n");
                break;
            case 5:
                printf("\nPostorder Traversal: ");
                postorder(h);
                printf("\n");
                break;
            case 6:
                return 0;
            default:
                printf("\nEnter a valid input\n");
        }
    }
    return 0;
}
/* 
Output

==== AVL Tree Menu =====
1. Insertion
2. Search
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit

Enter your choice: 1
Enter value to insert: 30
Inserted and balanced successfully.

Enter your choice: 1
Enter value to insert: 20
Inserted and balanced successfully.

Enter your choice: 1
Enter value to insert: 10
Inserted and balanced successfully.

Enter your choice: 3
Inorder Traversal: 10 20 30

Enter your choice: 4
Preorder Traversal: 20 10 30

Enter your choice: 5
Postorder Traversal: 10 30 20

Enter your choice: 2
Enter key: 20
Key is found

Enter your choice: 6
*/
