#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 9

int printSolution(int dist[], int n)
{
	int i;
   	printf("Vertex   Distance from Source\n");
   	for (i = 0; i < V; i++)
    	printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V], count, i;
    bool sptSet[V];
    for (i = 0; i < V; i++)
    	dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
    for (count = 0; count < V-1; count++)
    {
    	int u = minDistance(dist, sptSet), v;
		sptSet[u] = true;
      	for (v = 0; v < V; v++)
        	if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
           		dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}
int minDistance(int dist[], bool sptSet[])
{
   	int min = INT_MAX, min_index, v;
   	for (v = 0; v < V; v++)
    	if (sptSet[v] == false && dist[v] <= min)
        	min = dist[v], min_index = v;
   	return min_index;
} 
int main()
{
   	int graph[V][V], i, j;
   	for(i=0; i<V; i++)
   	{
   		for(j=0; j<V; j++)
   			scanf("%d", &graph[i][j]);
   	}
   	dijkstra(graph, 0);
  	return 0;
}
