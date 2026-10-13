/* Name:Aswani p.j
   Roll No :CS05
   Date :03-09-2026
*******************************

Ex No:13
Aim:Conversion  of  an  infix  expression  to  the  postfix  form  using  stacks.

**********Algorithm************

Step1:Start
Step2:Read the infix expression.
Step3:Create an empty stack.
Step4:Read each character one by one.
Step5:If it is an operand, add it to postfix.
Step6:If it is (, push it into the stack.
Step7:If it is ), pop until ( is found.
Step8:If it is an operator, pop operators with higher or equal precedence, then push the operator.
Step9:After reading all characters, pop the remaining operators.
Step10:Display the postfix expression.
Step11:Stop.

******Source code******
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char d;
	struct node* next;
}n;

n* createnode(char d){
  n* nn=(n*)malloc(sizeof(n));
  nn->d=d;
  nn->next=NULL;
  return nn;
}

void push(n** h, char d);
char pop(n** h);
char peek(n** h);
int precedence(char c);
void infixtopostfix(char* infix, char* postfix);

int main(){
	char infix[100], postfix[100];
    
	printf("\nEnter infix expression :");
	scanf("%s", infix);
    
	infixtopostfix(infix, postfix);
    
	printf("Postfix expression :%s\n", postfix);
	return 0;
}

void push (n** h, char d){
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; return;}
  else{nn->next=*h; *h=nn;}
  return;
}

char pop (n** h){
  if(*h==NULL){return '\0';} 
  n* t=*h;
  char popped = t->d;
  *h=(*h)->next;
  free(t);
  return popped;
}

char peek(n** h){
  if(*h==NULL){return '\0';}
  return (*h)->d;
}

int precedence(char c){
  if(c == '^') return 3;
  if(c == '*' || c == '/') return 2;
  if(c == '+' || c == '-') return 1;
  return -1;
}

void infixtopostfix(char* infix, char* postfix){
  n* head = NULL;
  int i = 0, j = 0;
  
  while(infix[i] != '\0'){
    char c = infix[i];
     
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
      postfix[j++] = c;
    }
  
    else if(c == '('){
      push(&head, c);
    }

    else if(c == ')'){
      while(head != NULL && peek(&head) != '('){
        postfix[j++] = pop(&head);
      }
      if(head != NULL) pop(&head); // Remove '(' from stack
    }
    
    else{
      while(head != NULL && precedence(peek(&head)) >= precedence(c)){
        postfix[j++] = pop(&head);
      }
      push(&head, c);
    }
    i++;
  }
  
  while(head != NULL){
    postfix[j++] = pop(&head);
  }
  
  postfix[j] = '\0';
}

/* Output
	
Enter infix expression : A+B*C
Postfix expression : ABC*+
*/
