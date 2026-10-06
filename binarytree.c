/* Name:Aswani p.j
   Roll No :CS05
   Date :
*******************************
Ex No:1
Aim: Implementation of stack using arrays


**********Algorithm************

Step1:Start
Step2:Set top = -1.
Step3:Read array size.
Step4:Display menu.
Step5:Choose Push, Pop, Peek or Exit.
Step6:Push: If stack is full → Overflow, otherwise insert element.
Step7:Pop: If stack is empty → Underflow, otherwise remove top element.
Step8:Peek: Display the top element.
Step9:Repeat until Exit.
Step10:Stop.


******Source code******
*/


#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node*left,*right;
};
struct node* insert(int data){
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->right=NULL;
        newnode->left=NULL;
        return newnode;
}
void preorder(struct node*root){
        if(root!=NULL){
                printf("%d",root->data);
                preorder(root->left);
                preorder(root->right);
        }
}
void inorder(struct node*root){
        if(root!=NULL){
                inorder(root->left);
                printf("%d",root->data);
                inorder(root->right);
        }
}
void postorder(struct node*root){
        if(root!=NULL){
                postorder(root->left);
                postorder(root->right);
                printf("%d",root->data);
        }
}
int main(){
        struct node*root;
        struct node*node[10];
        int n,i,data;
        printf("Enter the noof nodes:\n");
        scanf("%d",&n);
        printf("Enter the elements:\n");
        for(i=0;i<n;i++){
                scanf("%d",&data);
                node[i]=insert(data);
        }
        root=node[0];
        for(i=0;i<n;i++){
                if(2*i+1<n)
                        node[i]->left=node[2*i+1];
                if(2*i+2<n)
                        node[i]->right=node[2*i+2];
        }
        printf("Preorder:\n");
        preorder(root);
        printf("\nInoredr:\n");
        inorder(root);
        printf("\nPostorder:\n");
        postorder(root);
        return 0;
}


