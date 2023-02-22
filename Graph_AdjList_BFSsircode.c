#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
int vertex;
struct node *next;
};

int front=-1;			/* Queue is empty*/
int rear=-1;
int Q[size];

struct node *createNode(int vertext){
	struct node *nn;
	nn = (struct node *) malloc(sizeof(struct node));
	nn->vertex = vertext;
	nn->next =  NULL;
	return nn;
}

void enq(int v){
	if(rear >= size-1){			/*When Queue is Full*/
		printf("Queue overflow\n");
		return;
	}
	else if(front == -1 && rear == -1)	/*When Queue is empty*/
		front = rear = 0;
	else					/*When Queue is not empty*/
		rear = rear + 1;

	Q[rear] = v;
	//printf("enqued");
}
int deq(){
	if(front == -1 || front >rear){		/*When Queue is empty*/
		printf("Queue underflow\n");
		return 0;
	}
	return Q[front++];			/*When Queue is not empty*/
}

void insert(struct node *adjList[], int s, int d) {
    struct node* dest = createNode(d);
    dest->next = adjList[s];
    adjList[s] = dest;
// (0,1) (0,2) (0,3)    1<-2<-3
    struct node* src = createNode(s);
    src->next = adjList[d];
    adjList[d] = src;
}

void BFS(struct node *adjList []) {
   int visited[size],i;
    for(i = 0; i< size; i++){
        visited[i] = 0;
    }
    int sv = 0;
  enq(sv);
  visited[sv]  = 1;

  while (front<=rear) {
    int v = deq();
    printf("%d \t", v);
    struct node* temp = adjList[v];
    while(temp != NULL){
    //printf(" hello %d \t", temp->vertex);
       if(visited[temp->vertex] == 0){
            enq(temp->vertex);
            visited[temp->vertex]  = 1;
        }
        temp = temp->next;
    }
  }
}

void display(struct node*adjList [])
{
  int v;
  for (v = 0; v < size; v++) {
    struct node* temp = adjList[v];
    printf("\n %d ", v);
    while (temp) {
      printf("-> %d\t", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void main(){
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
