#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* create(int x){
	struct node *newn;
	newn = (struct node*)malloc(sizeof(struct node));
	newn->data = x;
	newn->next = NULL;
	return newn;
}
struct node* hashing(int *a,int n){
	struct node *hash = (struct node*)malloc(sizeof(struct node));
	int i;
	for(i=0;i<n;i++){
		(hash+i)->data = -999;
		(hash+i)->next = NULL;
	}
	int pos;
	for(i=0;i<n;i++){
		pos = *(a+i)%n;
		if((hash+i)->data==-999){
			(hash+pos)->data = a[i];
		}
		else{
			struct node *temp;
			temp = (hash+pos)->next;
			if(temp!=NULL){
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->next = create(a[i]);
			}
			else{
				temp = (hash+pos)->next;
				temp = create(a[i]);
			}
		}
	}
	return hash;
}
int main(){
	int i,n;
	printf("Enter no.of elements:");
	scanf("%d",&n);
	struct node *hash;
	int a[n];
	printf("Enter elements into array:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    hash = hashing(a,n);
	printf("Elements after hashing:");
	for(i=0;i<n;i++){
		printf("%d ",(hash+i)->data);
	}
}

