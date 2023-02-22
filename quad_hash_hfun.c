#include<stdio.h>
#include<stdlib.h>
int m;
int* linear_hashing(int *,int);
int main()
{
	int n,i,j,key,u;
	printf("Enter No.of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter Elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int *b=linear_hashing(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",*(b+i));
	}
	printf("\n");
	printf("::Searching::\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter Element to search: ");
		scanf("%d",&key);
		u=(2*key)+3;
		if(b[u%n]==key)
		{
			printf("\nFound at Index: %d",key%n);
			printf(" O(1)");
		}
		else
		{
			for(j=0;j<n;j++)
			{
				if(b[(u+j)%n]==key)
					printf("\nFound at index: %d",(u+j)%n);
			}
		}
	}
}
int* linear_hashing(int *a,int n)
{
	printf("Entered into function\n");
	int m=n,j,i,u;
	int *b=(int *)malloc(m*sizeof(int));
	for(i=0;i<n;i++)
		b[i]=-1;
	for(i=0;i<n;i++)
	{
		u=((2*a[i])+3)%m;
	        if(b[u]==-1)
	        {
	        	b[u]=a[i];
	        }
	        else
	        {
	        	for(j=0;j<n;j++)
	        	{
	        		if(b[(u+(j*j))%n]==-1)
	        		{
	        			b[(u+(j*j))%n]=a[i];
	        			j=n;
	        		}
	        	}
	        	
	        }
	        
	}
	printf("Returned\n");
	return b;
}
