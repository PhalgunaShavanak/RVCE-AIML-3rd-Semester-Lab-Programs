#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	char line[80];
	struct node *llink,*rlink;};
struct node *first=NULL,*temp;
int count=0;

void display(struct node *t){
	temp=t;
	while(temp){
		printf("%s\n",temp->line);
		temp=temp->rlink;
	}
}

void append(char s[]){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->llink=new->rlink=NULL;
	strcpy(new->line,s);
	if(!first){
		first=new;
		count++;}
	else{
		struct node*temp=first;
		while(temp->rlink) temp=temp->rlink;
		count++;
		temp->rlink=new;
		new->llink=temp;
		}
}

void insert(char s[],int p){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->llink=new->rlink=NULL;
	strcpy(new->line,s);
	if(p==1){
		new->rlink=first;
		first->llink=new;
		first=new;}
	else if(p>count+1) printf("No position available\n");
	else if(p==count+1){
		struct node*temp=first;
		while(temp->rlink) temp=temp->rlink;
		temp->rlink=new;
		new->llink=temp;}
	else{
		struct node*temp=first;
		for(int i=2;i<p;i++) temp=temp->rlink;
		
		new->llink=temp;
		new->rlink=temp->rlink;
		temp->rlink->llink=new;
		temp->rlink=new;
	}
}

void delete(int p){
	if(!first) printf("No text exists\n");
	if(p==1){
		first=first->rlink;
		first->llink=NULL;
		count--;
	}
	else if(p>count){printf("not possible\n");}
	else{
		struct node * prev=NULL,* next=first;
		for(int i=2;i<=p;i++){
			prev=next;
			next=next->rlink;}
		prev->rlink=next->rlink;
		next->rlink->llink=prev;
		next->llink=next->rlink=NULL;
		free(next);
		count --;
	}
}

int main(){
	char text[80],buffer[80];
	char end[]="End";
	while(1){
		printf("Enter text:\n");
		scanf(" %[^\n]s",text);
		if(!strcmp(text,end)) break;
		append(text);
	}
	display(first);
	printf("Enter the text to insert:\n");
	scanf(" %[^\n]s",buffer);
	int pos;
	printf("Enter the position\n");
	scanf("%d",&pos);
	insert(buffer,pos);
	display(first);
	printf("Enter the position to delete\n");
	scanf("%d",&pos);
	delete(pos);
	display(first);
	return 0;
}
