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
	newn->right = NULL;
	newn->left = NULL;
	return newn;
}
struct bst* insertnode(struct bst* root,int val){
	if(root==NULL){
		root=create(val);
	}else if((root->data)<val){
		root->right=insertnode(root->right,val);
	}else{
		root->left=insertnode(root->left,val);
	}
	return root;
}

struct bst* deletionnn(struct bst* root,int val){
	if(!root)return root;
	else if((root->data)<val){
		root->right=deletionnn(root->right,val);
	}else if((root->data)>val){
		root->left=deletionnn(root->left,val);
	}else{
		if(root->right && root->left){
			struct bst* succer=(root->right);
			while((succer->left)!=NULL)succer=succer->left;
			root->data=succer->data;
			root->right=deletionnn(root->right,succer->data);
		}else{
			if(root->right)return (root->right);
			else return (root->left);
			free(root);
		}
	}
	return root;
}

struct bst* searchh(struct bst* root,int val){
	if(root==NULL || root->data==val){
		return root;
	}else if((root->data)<val){
	 	searchh(root->right,val);
	}else{
	 	searchh(root->left,val);
	}
}

void printpre(struct bst* root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->data);
	printpre(root->left);
	printpre(root->right);
}
int main(){
	struct bst *root=NULL;
	root=insertnode(root,6);
	root=insertnode(root,8);
	root=insertnode(root,5);
	root=insertnode(root,7);
	root=insertnode(root,9);
	root=insertnode(root,4);
	root=insertnode(root,16);
	root=insertnode(root,10);
	root=deletionnn(root,8); 
	//          6
	//       5     8
	//     4     7   9
	// 6 5 4 8 7 9
	printpre(root);
}
