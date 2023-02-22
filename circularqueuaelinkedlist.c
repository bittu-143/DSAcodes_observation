#include<stdio.h>
#include<stdlib.h>
struct q{
	int data;
	struct q *next;
};
struct q *rare = NULL;
struct q *front = NULL;
void enque(int x){
	struct q *new = (struct q *)malloc(sizeof(struct q));
	new->data = x;
	new->next=NULL;
	if(rare==NULL){
		rare = new;
		front = new;
		rare->next = front;
	}
	else{
		rare->next = new;
		rare = new;
		rare->next = front;
	}
}

void deque(){
	struct q *temp;
	temp = front;
	if(rare==NULL && front==NULL){
		printf("Empty quauae");
	}
	else if(front==rare){
		printf("\n%d\n",front->data);
		front = NULL;
		rare = NULL;
		free(temp);
	}
	else{
		printf("\n%d\n",front->data);
		front = front->next;
		rare->next = front;
		free(temp);
	}
}

void peek(){
	if(rare==NULL && front==NULL){
		printf("Empty quauae");
	}
	else{
		printf("\n%d\n",front->data);
    }
}

void display(){
	struct q *temp;
	temp = front;
	if(rare==NULL && front==NULL){
		printf("Empty quauae");
	}
	else{
		printf("%d ",temp->data);
		temp = temp->next;
		while(temp!=front){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}

int main(){
	enque(1);
	enque(3);
	enque(6);
	enque(10);
	display();
	deque();
	display();
	deque();
	display();
	peek();
}
