#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6

int top = -1;
int stackarr[MAX];

int isFull(){
	if(top==MAX)
	    return top==MAX;
	else
	    return top==MAX;
}
int isEmpty(){
	if(top==-1)
	    return 1;
	else return 0;
}

void pushwithtop0(int data){
	if(isFull()){
	    printf("stack full");
	    return;
	}
	top++;
	int i;
	for(i=top;i>0;i--){
		stackarr[i]=stackarr[i-1];
	}
	stackarr[0] = data;
}
void push(int data){
	if(isFull()){
	    printf("stack full");
	    return;
	}
	top++;
	stackarr[top] = data;
}
void printwithtopas0(){
	int i;
	for(i=0;i<=top;i++){
		printf("%d ",stackarr[i]);
		printf("\n");
	}
}
void print(){
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",stackarr[i]);
	}
	printf("\n");
}
void pop(){
	if(isEmpty()){
		printf("Empty");
		return;
	}
	printf("%d",stackarr[top]);
	printf("\n");
	top--;
}
int main(){
	push(3);
	push(2);
	push(1);
	push(0);
	push(-1);
	push(4);
	push(5);
	print();
	pop();
	print();
}
