#include<stdio.h>
#include<stdlib.h>
#define size 8
struct node{
int vertex;
struct node *next;
};
int top = -1;
int S[size];



struct node *createNode(int vertext){
	struct node *nn;
	nn = (struct node *) malloc(sizeof(struct node));
	nn->vertex = vertext;
	nn->next =  NULL;
	return nn;
}

void insert(struct node *adjList[], int s, int d) {
    struct node* dest = createNode(d);
    dest->next = adjList[s];
    adjList[s] = dest;

    struct node* src = createNode(s);
    src->next = adjList[d];
    adjList[d] = src;
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

void push(int v){
	if(top >= size-1){
		printf("Stack is full\n");
		return;
	}else{
	S[++top] = v;
	}
}
int pop(){
	if(top < 0){
		printf("Stack underflow\n");
		return 0;
	}
	return S[top--];
}

void DFS(struct node *adjList []) {
    int visited[size];
    for(int i = 0; i< size; i++){
        visited[i] = 0;
    }
    int sv = 0;
    push(sv);
    //printf("%d", sv);
    while (top >= 0) {
    int v = pop();
    if(visited[v] == 0){
            printf("%d\t ", v);
            visited[v]  = 1;
    }
    struct node* temp = adjList[v];
    while(temp !=NULL){
       if(visited[temp->vertex] == 0){
            push(temp->vertex);
        }
        temp = temp->next;
    }
  }


}

void main(){
struct node *adjList[size];
for(int i = 0; i< size; i++){
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

DFS(adjList);

}
