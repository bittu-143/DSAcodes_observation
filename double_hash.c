#include<stdio.h>
#include<stdlib.h>
int m;
int* double_hash(int *,int);
int main()
{
	int n,i,u,v,j,key;
	printf("Enter No.of Elements: ");
	scanf("%d",&n);
	int a[n];
	m=n+5;
	printf("::Enter Elements::\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int *b=double_hash(a,n);
	for(i=0;i<m;i++)
	{
		printf("%d ",*(b+i));
	}
	printf("\n");
	printf("::Searching::\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter Element to search: ");
		scanf("%d",&key);
		u=(2*key+3);
		v=(3*key+1);
		if(b[u%n]==key)
		{
			printf("\nFound at Index: %d",key%n);
			printf(" O(1)");
		}
		else
		{
			for(j=0;j<m;j++)
			{
				if(b[(u+(v*j))%m]==key)
				{
					printf("\nFound at index: %d",(u+v*j)%m);
					break;
				}
			}
		}
	}
}
int* double_hash(int *a,int n)
{
	int m=n+5,i,j,u,v,k;
	int *b=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		*(b+i)=-1;
	for(i=0;i<n;i++)
	{
		u=(2*a[i]+3);
		v=(3*a[i]+1);
		if(b[u%m]==-1)
			b[u%m]=a[i];
		else
		{
			for(j=0;j<m;j++)
			{
				k=u+(v*j);
				if(b[k%m]==-1)
				{
					b[k%m]=a[i];
					j=m;
				}
			}
		}

	}
	return b;
}
