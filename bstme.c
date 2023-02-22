#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	struct bst *left,*right;
};
struct bst* create(int x){
	struct bst *newn;
	newn = (struct bst*)malloc(sizeof(struct bst));
	newn->data = x;
	newn->left = NULL;
	newn->right = NULL;
	return newn;
}
struct bst* insert(struct bst* root,int x){
	if(!root) root = create(x);
	else if(x>root->data){
		root->right = insert(root->right,x);
	}
	else{
		root->left = insert(root->left,x);
	}
	return root;
}
void print(struct bst* root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	print(root->left);
	print(root->right);
}
struct bst* del(struct bst *root,int x){
	if()
}
int main(){
	struct bst *root = NULL;
	root = insert(root,10);
	root = insert(root,13);
	root = insert(root,3);
	root = insert(root,14);
	root = insert(root,5);
	root = insert(root,2);
	root = insert(root,11);
	//      10
	//   3        13
	// 2   5   11    14
	// 10 3 2 5 13 11 14
	print(root);
}
