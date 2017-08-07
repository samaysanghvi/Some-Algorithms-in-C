#include<stdio.h>
#define MAX 100
int prev[MAX];
int dist[MAX];
void shortestdistance(int n,int cost[][MAX],int dist[],int u)
{
	int i,v,w;
	int found[MAX],min;
	for(i=0;i<n;i++)
	{
		found[i]=0;
		dist[i]=cost[u][i];
		prev[i]=u;
	}
	found[u]=1;
	dist[u]=0;
	for(i=0;i<n-1;i++)
	{
		min=100;
		for(v=0;v<n;v++)
		{
			if(found[v]==0)
			{
				if(min>dist[v])
				{
					min=dist[v];
					w=v;
				}
			}
		}
		found[w]=1;
		for(v=0;v<n;v++)
		{
			if(found[v]==0)
			{
				if(dist[v]>dist[w]+cost[w][v])
				{
					dist[v]=dist[w]+cost[w][v];
					prev[v]=w;
				}
			}
		}
	}
}

int main()
{
	int cost[MAX][MAX],V,i,j,k;
	int path[MAX];
	
	int s,d,sum=0;
	printf("Enter number of vertices\n");
	scanf("%d",&V);
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	printf("Enter the pair of vertices\n");
	scanf("%d%d",&s,&d);
	if(cost[s][d]==1)
	{
		printf("Least no. of edges between %d and %d is 1 and the there is direct edge between them ",s,d);
	}
	else
	{
	
	shortestdistance(V,cost,dist,s);i=d;
	printf("The path is -> ");
	path[0]=d;k=1;
	while(i!=s)
	{
		sum++;
		i=prev[i];
		path[k]=i;
		k++;
	}
	for(i=k-1;i>=0;i--)
	{
		printf("%d ",path[i]);
	}
	
	printf("\n\nNumber of edges between %d & %d is %d",s,d,sum);
}
}

