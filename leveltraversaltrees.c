#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define MAX 6
// stack
int top = -1;
int stackarr[MAX];

int isFull(){
	if(top==MAX)
	    return top==MAX;
	else
	    return top==MAX;
}
int isEmpty(){
	if(top==-1)
	    return 1;
	else return 0;
}

void push(int data){
	if(isFull()){
	    printf("stack full");
	    return;
	}
	top++;
	stackarr[top] = data;
}

void print(){
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",stackarr[i]);
	}
	printf("\n");
}
void pop(){
	if(isEmpty()){
		printf("Empty");
		return;
	}
	printf("%d",stackarr[top]);
	printf("\n");
	top--;
}

// tree
struct node {
  int item;
  struct node* left;
  struct node* right;
};
// Create a new Node
struct node* create(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = create(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = create(value);
  return root->right;
}


int main() {
  struct node* root = create(1);
  //              1
  insertRight(root,2);
  insertLeft(root,3);
  //        1
  //      3   2
  insertRight(root->right,4);
  insertLeft(root->right,5);
  //         1
  //     3       2
  //   x  x    5   4
  insertRight(root->left,6);
  insertLeft(root->left,7);
  //         1
  //     3       2
  //   7   6   5   4
  
}
