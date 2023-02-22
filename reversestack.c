#include<stdio.h>
#include<stdlib.h>
struct stack{
	int n;
	struct stack* next;
};
struct stack* push(int data,struct stack* top){
	struct stack *new;
	new = malloc(sizeof(struct stack));
	new->n = data;
	new->next = NULL;
	
	new->next = top;
	top = new;
	
	return top;
}
void print(struct stack* top){
	while(top!=NULL){
		printf("%d ",top->n);
		top = top->next;
	}
}

struct stack* pop(struct stack* top){
	struct stack *temp;
	temp = top;
	top = top->next;
	return temp;
}
int main(){
	struct stack *top = NULL;
	struct stack *top1 = NULL;
	struct stack *top2 = NULL;
	top = push(1,top);
	top = push(2,top);
	top = push(3,top);
	print(top);
	struct stack *temp = NULL;
	while(top!=NULL){
		temp = pop(top);
		top1 = push(temp->n,top1);
		top = temp->next;
	}
	print(top1);
}
