#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int i,c,root,temp,j;
	int heap[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&heap[i]);
	}
	for(i=1;i<n;i++)
	{
		c=i;
		do{
			root=(c-1)/2;
			if(heap[root]<heap[c])
			{
				temp=heap[root];
				heap[root]=heap[c];
				heap[c]=temp;
			}
			c=root;
		}while(c!=0);
	}
	for(j=n-1;j>=0;j--)
	{
		temp=heap[0];
		heap[0]=heap[j];
		heap[j]=temp;
		root=0;
		do{
			c=2*root+1;
			if(heap[c]<heap[c+1] && c<j-1)
			{
				c++;
			}
			if(heap[root]<heap[c] && c<j)
			{
				temp=heap[root];
				heap[root]=heap[c];
				heap[c]=temp;
			}
			root=c;
		}while(c<j);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",heap[i]);
	}
}
