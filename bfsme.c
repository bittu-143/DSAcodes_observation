#include<stdio.h>
#include<stdlib.h>
#define size 10
int q[size];
int front = -1;
int rare = -1;
struct node{
	int data;
	struct node *next;
};
struct node* create(int x){
	struct node *nn;
	nn = (struct node*)malloc(sizeof(struct node));
	nn->data = x;
	nn->next = NULL;
	return nn;
}
void enq(int x){
	if(rare>=(size-1))
	{
		printf("Queue overflow");
		return;
	}
	else if(front==-1 && rare==-1){
		front = 0;
		rare = 0;
	}
	else{
		rare = rare+1;
	}
	q[rare] = x;
}
int deque(){
	if(front>rare || front == -1){
		printf("Queue underflow\n");
		return 0;
	}
	return q[front++];
}
void insert(struct node *adj[],int s,int d){
	struct node* nnn = create(d);
	nnn->next = adj[s];
	adj[s] = nnn;
	
	struct node *ser = create(s);
	ser->next = adj[d];
	adj[d] = ser;
}
void display(struct node *adj[]){
	int i;
	for(i=0;i<size;i++){
		struct node *temp = adj[i];
		printf("\n%d ",i);
		while(temp){
			printf("->%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
void BFS(struct node *adj[]){
	int i,visited[size];
	for(i=0;i<size;i++){
		visited[i] = 0;
	}
	int root = 0;
	enq(root);
	visited[root] = 1;
	while(front<=rare){
		int o = deque(root);
		printf("%d ",o);
		struct node* temp = adj[o];
		while(temp!=NULL){
			if(visited[temp->data]==0)
			{
				enq(temp->data);
				visited[temp->data] = 1;
			}
			temp = temp->next;
		}
	}
}
int main(){
	int i;
	struct node *adjList[size];
	for(i = 0; i< size; i++){
	    adjList[i] = NULL;
	}
	insert(adjList,0,  1);
	insert(adjList,0,  2);
	insert(adjList,1,  3);
	insert(adjList,1,  4);
	insert(adjList,2,  5);
	insert(adjList,2,  6);
	insert(adjList,4,  7);
	insert(adjList,3,  7);
	insert(adjList,6,  7);
	insert(adjList,5,  7);

	display(adjList);

	BFS(adjList);
}
