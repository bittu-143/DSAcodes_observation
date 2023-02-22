#include<stdio.h>
#include<stdlib.h>
//linear-hashing
int* hasharray(int *a,int n){
	int *b,i,hash,j,m;
	b = (int*)malloc(sizeof(int));
	for(i=0;i<n;i++){
		b[i] = -1;
	}
	for(i=0;i<n;i++){
		hash = *(a+i)%n;
		if(b[hash]==-1){
			b[hash] = *(a+i);
		}
		else{
			for(j=0;j<m;j++){
				int k = (hash+j)%n;
				if(b[k]==-1){
					b[k] = *(a+i);
					break;
				}
			}
		}
	}
	return b;
}

int main(){
	int n;
	printf("Enter no.of elements:");
	scanf("%d",&n);
	int a[n],i;
	printf("Enter elemets:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int *b;
	b = hasharray(a,n);
	printf("Array after hashing:");
	for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("Enter element to search:");
	int ser;
	scanf("%d",&ser);
	int pos = ser%n;
	if(b[pos]==ser){
		printf("Found the element at %d",pos);
	}
	else{
		i = 0;
		while(1){
			int hem = (pos+i)%n;
			if(b[hem]==ser){
				printf("Found in b at position %d",hem);
				break;
			}
			else
				i++;
		}
	}
}
