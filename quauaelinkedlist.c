#include<stdio.h>
#include<stdlib.h>
struct q{
	int data;
	struct q *next;
};
struct q *rare = NULL;
struct q *front = NULL;

void enque(int x){
	struct q *new;
	new = (struct q*)malloc(sizeof(struct q));
	new->data = x;
	new->next = 0;
	if(rare == NULL && front == NULL){
		rare=new;
		front = new;
	}
	else{
		rare->next = new;
		rare = new;
	}
}

void display(){
	struct q *temp = front;
	if(front==NULL && rare == NULL){
		printf("Empty quaue");
	}
	else{
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}
void deque(){
	if(rare==front){
		printf("\n%d\n",front->data);
		rare = NULL;
		front = NULL;
	}
	else{
		printf("\n%d\n",front->data);
		front = front->next;
	}
}
void peek(){
	if(front==NULL && rare==NULL){
		printf("Empty que");
	}
	else{
		printf("\n%d\n",front->data);
	}
}

int main(){
	enque(1);
	enque(2);
	enque(4);
	enque(10);
	display();
	deque();
	display();
	peek();
}
