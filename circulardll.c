#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node* createdll(struct node *first){
	int x,i,n;
	printf("enter number of nodes:");
	struct node *temp;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		struct node *new = (struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&n);
		if(i==0){
			new->data = n;
			new->next = NULL;
			new->prev = NULL;
			first = new;
			temp = first;
		}
		else{
			new->data = n;
			new->next = NULL;
			new->prev = NULL;
			temp->next = new;
			new->prev = temp;
			temp = temp->next;
		}
		if(i==(n-1)){
			new->next = first;
			first->prev = new;
		}
	}
	return first;
}
void print(struct node *first){
	struct node *temp;
	temp = first;
	while(temp->next!=first){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main(){
	struct node *first;
	first = createdll(first);
	print(first);
}
