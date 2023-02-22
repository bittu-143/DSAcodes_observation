#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,j;
	int *(*b) = (int**)malloc(2*sizeof(int*));
	for(i=0;i<2;i++){
		*(b+i) = (int*)malloc(3*sizeof(int));
		for(j=0;j<3;j++){
			scanf("%d",(*(b+i)+j));
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
		printf("%d ",b[i][j]);
		printf("\n");
	}
}
