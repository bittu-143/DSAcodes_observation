#include<stdio.h>
#define n 6 //defines a constant globally it can be used anytime
int a[n]; //defining globally an array of size n
int rare = -1; // rare is the tale of the array starting from -1
int front = -1; // front is the head of the array starting from -1
void enque(int x){ // a function used to add elements at tail
	if(rare==-1 && front == -1){
		rare = 0; // if queuae is empty we need to initilize rare and front by 0
		front  = 0;
		a[rare] = x; // now initialize a[0] with x parameter
	}
	else{ //if the queuae is not empty then increase rare and initualize a[rare] with x
		rare++; // increase rare to move forward to initialize next data input given
		a[rare] = x;
	}
}
void deque(){ // a function used to deleate elements from head
	if(rare==front){
		rare = -1;
		front = -1;
		printf("quauae is empty");
	}
	else{
		printf("\n%d\n",a[front]);
		front++;
	}
}

void peek(){
	if(rare==-1 && front == -1){
		printf("Quauae is empty");
	}
	else{
		printf("%d",a[front]);
	}
}

void display(){//a function used to display the queae
	if(rare==-1 && front == -1){ // condition to check if queae is empty
		printf("Quauae is empty");
	}
	else{
		int i; // else condition to print quauae
		for(i=front;i<=rare;i++){
			printf("%d ",a[i]);
		}
	}
}
int main(){
	enque(1);
	enque(2);
	enque(6);
	enque(10);
	display();
	deque();
	display();
}
