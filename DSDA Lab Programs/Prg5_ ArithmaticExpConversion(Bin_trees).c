#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 100

int top=-1;
typedef struct node{
	char data;
	struct node*lchild,*rchild;}node;
node *stack[size];

void push(node * new){
	if(top==size-1){
		printf("Overflow");
		exit(0);
	}
	stack[++top]=new;
}	

node *pop(){
	if(top==-1){
		printf("UNderflow,invalid expression");
		exit(0);
	}
	return stack[top--];
}

int is_op(char sym){
	if((sym=='/') || (sym=='*') || (sym=='+') || (sym=='-')) return 1;
	return 0;
}

node *createTree(char exp[]){
	int i=0;
	char c=exp[i];
	while(c!='\0'){
		node * new = (node *) malloc(sizeof(node));
		new->data=c;
		new->lchild=new->rchild=NULL;
		
		if (isalnum(c)) push(new);
		else if(is_op(c)){
			new->rchild=pop();
			new->lchild=pop();
			push(new);
		}
		else{
			printf("Invalid symbol %c detected\n",c);
			exit(0);
		}
		c=exp[++i];
	}
	return pop();
}

void infix(node *root){
	if(root){
		infix(root->lchild);
		printf("%c",root->data);
		infix(root->rchild);
	}
}

void prefix(node *root){
	if(root){
		printf("%c",root->data);
		prefix(root->lchild);
		prefix(root->rchild);		
	}
}

void postfix(node *root){
	if(root){
		postfix(root->lchild);
		postfix(root->rchild);		
		printf("%c",root->data);
	}
}
void check(char p[]){
	int i=0,d=0;
	while(p[i]!='\0'){		
		if (isalnum(p[i])) d++;
		else if(is_op(p[i])){
			d-=2;
			if(d<0) break;
			//push(new);
		}
		else{
			printf("Invalid symbol %c detected\n",p[i]);
			exit(0);
		}
		
		i++;		
	}
	if(d!=0){printf("Invalid expression");exit(0);}
	else printf("Valid\n");
	
}

int main(){
	char pf[100];
	printf("Enter postfix expression:");
	scanf("%s",pf);
	check(pf);
	node *tree=createTree(pf);
	printf("Infix expression:"); infix(tree);printf("\n");
	printf("Prefix expression:"); prefix(tree);printf("\n");
	printf("Postfix expression:"); postfix(tree);printf("\n");
}