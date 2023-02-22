#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* createll(struct node *first){
	int x,i,n;
	printf("enter number of nodes:");
	struct node *temp;
	scanf("%d",&x);
	for(i=0;i<n;i++){
		struct node *new = (struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&n);
		if(i==0){
			new->data = n;
			new->next = NULL;
			first = new;
			temp = first;
		}
		else{
			new->data = n;
			new->next = NULL;
			temp->next = new;
			temp = temp->next;
		}
	}
	return first;
}
void print(struct node *first){
	struct node *temp;
	temp = first;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main(){
	struct node *first;
	first = createll(first);
	print(first);
	
}
