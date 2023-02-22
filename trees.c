#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right,*left;
};
struct node* create(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	int da;
	printf("Enter the data:[enter -1 for no node]:");
	scanf("%d",&da);
	if(da!=-1){
		temp->data = da;
		printf("Enter right node of %d\n",da);
		temp->right = create();
		printf("Enter left node of %d\n",da);
		temp->left = create();
		return temp;
	}
	else{
		return NULL;
	}
	
}

//          1
//        5      2
//      6   7   4     3

// 1 2 3 4 5 7 6
void printpre(struct node *root){
	if(root==NULL){
		return;
	}
	printf("%d",root->data);
	printpre(root->right);
	printpre(root->left);
	
}
void printpost(struct node *root){
	if(root==NULL){
		return;
	}
	printpre(root->right);
	printpre(root->left);
	printf("%d",root->data);
}
void printin(struct node *root){
	if(root==NULL){
		return;
	}
	printpre(root->right);
	printf("%d",root->data);
	printpre(root->left);
}
int main(){
	struct node *root;
	root = create();
	printpre(root);
}
