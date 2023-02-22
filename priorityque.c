#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct que{
	int data;
	int priority;
};
#define max 10
struct que a[max];
int rare = -1;
int front = -1;
void enque(int x,int p){
	if(rare==(max-1)){
		printf("Queue full\n");
	}
	else{
		if(rare==-1 && front==-1){
			rare = 0;
			front = 0;
		}
		else{
			rare++;
		}
		a[rare].data = x;
		a[rare].priority = p;
	}
}
void sort(){
	int i,j;
	for(i=0;i<rare+1;i++){
		for(j=i+1;j<rare+1;j++){
			if(a[i].priority<a[j].priority){
				struct que temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int peek(){
	printf("%d is peek\n",a[front].data);
}

void deque(){
	int i;
	for(i=0;i<rare+1;i++){
		a[i] = a[i+1]; 
	}
	rare--;
}
void display(){
	int i;
	for(i=0;i<rare+1;i++){
		printf("%d ",a[i].data);
	}
	printf("\n");
}
int main(){
	enque(1,10);
	enque(2,20);
	enque(3,40);
	enque(12,23);
	enque(5,50);
	sort();
	display();
	peek();
	deque();
	display();
	peek();
	deque();
	display();
	peek();
	deque();
	display();
	peek();
}
