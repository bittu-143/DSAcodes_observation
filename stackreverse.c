#include<stdio.h>
#include<stdlib.h>
struct stack{
	int n;
	struct stack* next;
}; 

struct stack* push(int data,struct stack *top){
	struct stack *new;
	new = (struct stack*)malloc(sizeof(struct stack));
	
	new->n = data;
	new->next = NULL;
	
	new->next = top;
	top = new;
	return top;
}
void print(struct stack *top){
	struct stack *temp;
	temp = top;
	while(temp!=NULL){
		printf("%d ",temp->n);
		temp = temp->next;
	}
}

struct stack* pop(struct stack *top){
	struct stack *temp;
	if(top==NULL){
		printf("stack is empty");
	}
	else{
		temp = top;
		top = top->next;
		return temp;
	}
}
int main(){
	struct stack *top = NULL;
	struct stack *top1 = NULL;
	struct stack* temp;
	top = push(0,top);
	top = push(1,top);
	top = push(2,top);
	top = push(3,top);
	temp = pop(top);
	top = temp->next;
	top1 = push(temp->n,top1);
	temp = pop(top);
	top = temp->next;
	top1 = push(temp->n,top1);
	temp = pop(top);
	top = temp->next;
	top1 = push(temp->n,top1);
	temp = pop(top);
	top = temp->next;
	top1 = push(temp->n,top1);
	print(top1);	
}
