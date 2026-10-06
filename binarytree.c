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


