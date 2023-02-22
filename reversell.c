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
	for(i=0;i<x;i++){
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
struct node* reverse(struct node *first){
	struct node *t,*p,*c;
	t = first;
	p = first->next->next;
	c = first->next;
	int count = 0;
	int i = 0;
	struct node *temp;
	temp = first;
	while(temp!=NULL){
		count++;
		temp = temp->next;	
	}
	for(i=0;i<(count-2);i++){
		if(i==0){
			t->next = NULL;
			c->next = t;
		}
		if(i==(count-3)){
			p->next = c;
			first = p;
		}
		else{
			c->next = t;
		}
		t = c;
		c = p;
		p = p->next;
	}
	return first;
}
int main(){
	struct node *first;
	first = createll(first);
	printf("linked list before reversing:");
	print(first);
	printf("\nlinked list after reversing:");
	first = reverse(first);
	print(first);	
}
