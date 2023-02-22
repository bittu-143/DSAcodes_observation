#include<stdio.h>
#include<stdlib.h>
#define n 5
int a[5],b[5];
int top = -1;
int top1 = -1;
int count = 0;
void enque(int data,int *a){
	a[top++] = data;
	count++;
}
int pop(int a){
	if(top>=0){
		int x = a[top];
		top--;
		return x;
	}
	else{
		printf("Stack empty");
		return;
	}
}

void deque(){
	int j;
	for(j=0;j<count;j++){
		int c = pop(a);
		enque(c,b);
	}
	int k = pop(b);
	for(j=0;j<count;j++){
		int c = pop(b);
		enque(c,a);
	}
}
void print(){
	int j;
	for(j = 0;j<count;j++){
		printf("%d",a[j]);
	}
}
int main(){
	enque(1,a);
	enque(2,a);
	enque(3,a);
	print();
	deque();
	print();
	
}
