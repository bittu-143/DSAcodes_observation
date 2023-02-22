#include<stdio.h>
#define size 6
int queue[100];
int front=0,rear=0;
void enq(int val){
	queue[rear++] = val;
}
int deq(){
	return queue[front++];
}
int visited[size] = {0};
int main(){
	int graph[size][size] = {
		{0,1,1,0,0,1},
		{1,0,1,0,0,0},
		{1,1,0,1,1,0},
		{0,0,1,0,0,1},
		{0,0,1,0,0,0},
		{0,1,0,1,0,0}
	};
	int i;
	int sv = 0;
	enq(sv);
	visited[sv] = 1;
	while(front!=rear){
		int current = deq();
		printf("%d ",current);
		for(i=0;i<size;i++){
			if((graph[current][i]==1)&&(visited[i]==0)){
				visited[i] = 1;
				enq(i);
			}
		}
	}
}
