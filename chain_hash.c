#include<stdio.h>
#include<stdlib.h>
struct node* create(int);
struct node* chain_hash(int *,int);
struct node
{
	int val;
	struct node *next;
};
int main()
{
	int n,i,key,u;
	printf("Enter no.of Elements: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	struct node *hash_table=chain_hash(a,n);
	for(i=0;i<n;i++)
	{
		printf("start: %d ",hash_table[i].val);
		struct node *temp=hash_table[i].next;
		printf("Adj: ");
		while(temp!=NULL)
		{
			printf("%d ",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}
	printf("::Searching::\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Element to search: ");
		scanf("%d",&key);
		u=key%n;
		if(hash_table[u].val==key)
			printf("Found at index: %d\n",key%n);
		else
		{
			int c=0;
			struct node *temp=hash_table[u].next;
			while(temp!=NULL)
			{
				if(temp->val==key)
				{
					printf("Found at index %d at %d moves:\n",key%n,c);
					temp=temp->next;
				}
				c++;
			}
		}
	}
	
}
struct node* create(int val)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	return temp;
}
struct node* chain_hash(int *a,int n)
{
	int i,u;
	struct node *hash_table=(struct node*)malloc(n*sizeof(struct node));
	for(i=0;i<n;i++)
		hash_table[i].val=-999;
	for(i=0;i<n;i++)
	{
		u=a[i]%n;
		if(hash_table[u].val==-999)
		{
			hash_table[u].val=a[i];
		}
		else
		{
			struct node *temp=hash_table[u].next;
			if(temp!=NULL)
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=create(a[i]);
			}
			else
				hash_table[u].next=create(a[i]);
		}
			
	}
	return hash_table;
}
