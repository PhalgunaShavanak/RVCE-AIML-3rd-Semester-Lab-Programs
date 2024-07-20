#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int found=0;
typedef struct node{
		char info[20];
		struct node*lchild,*rchild;
}node;
		
node *bstCreate(node* root,char data[20]){
	if(!root){
		node *temp=(node *)malloc(sizeof(node));
		temp->lchild=temp->rchild=NULL;
		strcpy(temp->info,data);
		return temp;
	}
	if(strcmp(data,root->info) <= 0)
		root->lchild=bstCreate(root->lchild,data);
	else
		root->rchild=bstCreate(root->rchild,data);
	return root;
}

node *bstDisplay(node *root){
	if (root){
		bstDisplay(root->lchild);
		printf("%s ",root->info);
		bstDisplay(root->rchild);}
}

node *bstDelete(node *root,char word[20]){
	if(!root) return root;
	else{
		if(strcmp(word,root->info) < 0)
			root->lchild=bstDelete(root->lchild,word);
		else if(strcmp(word,root->info) > 0)
			root->rchild=bstDelete(root->rchild,word);
		else{
			found=1;
			if(root->lchild==root->rchild && root->lchild==NULL)
				return NULL;
			else if(root->lchild==NULL){
				node* temp=root->rchild;
				free(root);
				return temp;
			}
			else if(root->rchild==NULL){
				node* temp=root->lchild;
				free(root);
				return temp;
			}
			else{
				node*cur=root->rchild;
				while(cur->lchild) cur=cur->lchild;
				strcpy(root->info,cur->info);
				root->rchild=bstDelete(root->rchild,cur->info);
			}
		}
	}
	return root;
}

int main(){
	char word[20],end[]="end";
	node*root=NULL;
	while(1){
		printf("enter the word:");
		scanf("%s",word);
		if(strcmp(word,end)!=0)
			root=bstCreate(root,word);
		else break;
	}
	bstDisplay(root);
	printf("Enter the word to delete:");
	scanf("%s",word);
	root=bstDelete(root,word);
	bstDisplay(root);
	//printf("%s",root->info);
	return 0;
}
