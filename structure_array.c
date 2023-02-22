#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node{
int vertex;
struct node *next;
};
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
// (0,1) (0,2) (0,3)    1 node ->n = null ad[0] = 1  and 2 node->1 node
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

void main(){
	int i;
struct node *adjList[size];
for(i = 0; i< size; i++){
    adjList[i] = NULL;
}
insert(adjList,0,  1);
display(adjList);
insert(adjList,0,  2);
display(adjList);
//insert(adjList,1,  3);
//insert(adjList,1,  4);
//insert(adjList,2,  5);
//insert(adjList,2,  6);
//insert(adjList,4,  7);
//insert(adjList,3,  7);
//insert(adjList,6,  7);
//insert(adjList,5,  7);


//BFS(adjList);

}
