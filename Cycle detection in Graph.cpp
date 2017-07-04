#include<stdio.h>
#define MAX 9
bool visited[MAX];
void traverse(int v,int V,int graph[MAX][MAX],int p)
{
	int w;
	visited[v]=true;
	printf("%d ",v);
	for(w=0;w<V;w++)
	{
		if(graph[v][w]!=0)
		{
			if(!visited[w])
			{
					visited[w]=true;
				
				 traverse(w,V,graph,v);
			}
			else if(visited[w] && w!=p )
			{
				printf("Cycle present\n\n");
			}
		}
	}
	printf("\n");
}
void dfs(int graph[MAX][MAX],int V)
{
	int v;
	for(v=0;v<V;v++)
	{
		visited[v]=false;
	}
	for(v=0;v<V;v++)
	{
		if(!visited[v])
		{
			traverse(v,V,graph,v);
		}
	}
}
int main()
{
	int graph[MAX][MAX],V,i,j;
	printf("Enter number of vertices\n");
	scanf("%d",&V);
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	dfs(graph,V);
}
