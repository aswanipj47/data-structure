/* Name:Aswani p.j
   Roll No :CS05
   Date :17-09-2026
*******************************

Ex No:16
Aim: Implementation  of  Huffman  algorithm.

**********Algorithm************

Step1:Start
Step2:Read the input string.
Step3:Count the frequency of each character.
Step4:Find the unique characters and their frequencies.
Step5:Create a minimum heap using the characters and frequencies.
Step6:Remove the two nodes with the lowest frequencies.
Step7:Create a new node by adding their frequencies and insert it into the heap.
Step8:Repeat steps 6 and 7 until only one node remains.
Step9:Traverse the Huffman tree, assign 0 to left edges and 1 to right edges, and print each character with its frequency and Huffman code.
Step10:Stop.

******Source code******
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_STR_LEN 1000
#define ASCII_SIZE 256

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("  %c   |   %2d   |   ", root->data, root->freq);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printf("\nChar  |  Freq  |  Huffman Code\n");
    printf("-----------------------------\n");
    printCodes(root, arr, top);
}

int main() {
    char str[MAX_STR_LEN];
    int freq_map[ASCII_SIZE] = {0};

    printf("Enter the input string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

   
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Empty string entered.\n");
        return 1;
    }

    
    for (size_t i = 0; i < len; i++) {
        freq_map[(unsigned char)str[i]]++;
    }

   
    int unique_count = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq_map[i] > 0) {
            unique_count++;
        }
    }

    char* arr = (char*)malloc(unique_count * sizeof(char));
    int* freq = (int*)malloc(unique_count * sizeof(int));

    int index = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq_map[i] > 0) {
            arr[index] = (char)i;
            freq[index] = freq_map[i];
            index++;
        }
    }

    HuffmanCodes(arr, freq, unique_count);

    free(arr);
    free(freq);
    return 0;
}

/*
Output

Enter the input string: hello

Char  |  Freq  |  Huffman Code
-----------------------------
  h   |    1   |   110
  e   |    1   |   111
  l   |    2   |   10
  o   |    1   |   0
*/
