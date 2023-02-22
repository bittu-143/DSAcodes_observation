#include<stdio.h>
void heapify(int arr[],int N,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<N && arr[left]>arr[largest])
		largest=left;
	if(right<N && arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr,N,largest);
	}
}
void heapsort(int arr[],int N)
{
	for(int i=N/2 - 1;i>=0;i--)
	{
		heapify(arr,N,i);
	}
	for(int i=N-1;i>=0;i--){
		int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapify(arr,i,0);
	}
}
void printArray(int arr[],int N){	
	for(int i=0;i<N;i++){
		printf("%d",arr[i]);
		printf("\n");
	}
}
int main(){
	int arr[]={12,11,13,5,6,7};
	int N = sizeof(arr)/sizeof(arr[0]);
	printf("Before sorting: \n");
	printArray(arr,N);
	heapsort(arr,N);
	printf("Sorted array is : \n");
	printArray(arr,N);
	return 0;
}
