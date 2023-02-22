#include<stdio.h>
#include<stdlib.h>
struct stack{
	int n;
	struct stack* next;
}; 
struct stack *top = NULL;

void push(int data){
	struct stack *new;
	new = malloc(sizeof(struct stack));
	new->n = data;
	new->next = NULL;
	
	new->next = top;
	top = new;
}
void print(){
	while(top!=NULL){
		printf("%d ",top->n);
		top = top->next;
	}
}

int main(){
	push(0);
	push(1);
	push(2);
	push(3);
	push(4);
	print();
}
