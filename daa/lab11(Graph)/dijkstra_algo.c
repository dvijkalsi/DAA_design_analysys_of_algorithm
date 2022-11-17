// 1. From a given vertex in a weighted connected graph, Write a program to find shortest paths to
// other vertices using Dijkstra's algorithm. Draw simple, connected weighted graph with 8 vertices 
// and 16 edges, each with unique edge weight. Identify one vertex as a start vertex and obtain 
// shortest path using Dijkstra's algorithm. 
#include <limits.h>
#include <stdio.h>

#define V 8
int minDistance(int dist[], int sptSet[]) {
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
   if (sptSet[v] == 0 && dist[v] <= min)
      min = dist[v], min_index = v;
   return min_index;
}
int printSolution(int dist[], int n) {
   printf("Vertex Distance from Source");
   for (int i = 0; i < V; i++)
      printf("%d \t %d", i, dist[i]);
}
void dijkstra(int graph[V][V], int src) {
   int dist[V];
   int sptSet[V];
   for (int i = 0; i < V; i++)
      dist[i] = INT_MAX, sptSet[i] = 0;
      dist[src] = 0;
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet);
      sptSet[u] = 1;
      for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
   }
   printSolution(dist, V);
}
int main() {
   int graph[V][V] = { { 0, 6, 0, 0, 0, 0, 0, 8 },
      { 6, 0, 8, 0, 0, 0, 0, 13 },
      { 0, 8, 0, 7, 0, 6, 0, 0 },
      { 0, 0, 7, 0, 9, 14, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0 },
      { 0, 0, 6, 14, 10, 0, 2, 0 },
      { 0, 0, 0, 0, 0, 2, 0, 1 },
      { 8, 13, 0, 0, 0, 0, 1, 0 },
   };
   dijkstra(graph, 0);
   return 0;
}