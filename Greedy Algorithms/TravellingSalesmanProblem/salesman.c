#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 5

int findMinDistanceCity(int city, bool visited[], int graph[N][N])
{
  int minDistance = INT_MAX;
  int nearestCity = -1;

  for (int i = 0; i < N; i++)
  {
    if (!visited[i] && graph[city][i] != 0 && graph[city][i] < minDistance)
    {
      minDistance = graph[city][i];
      nearestCity = i;
    }
  }

  return nearestCity;
}

void travelingSalesman(int graph[N][N], int start)
{
  bool visited[N] = {false};
  int totalDistance = 0;
  int currentCity = start;

  printf("Traveling Salesman Path: %d -> ", start);
  visited[start] = true;

  for (int i = 0; i < N - 1; i++)
  {
    int nextCity = findMinDistanceCity(currentCity, visited, graph);
    if (nextCity == -1)
    {
      printf("Error: No valid path found!\n");
      return;
    }

    printf("%d -> ", nextCity);
    totalDistance += graph[currentCity][nextCity];
    visited[nextCity] = true;
    currentCity = nextCity;
  }

  totalDistance += graph[currentCity][start];
  printf("%d\n", start);
  printf("Total Distance: %d\n", totalDistance);
}

int main()
{
  int graph[N][N] = {
      {0, 10, 15, 20, 15},
      {10, 0, 25, 25, 17},
      {15, 45, 0, 30, 18},
      {20, 25, 30, 0, 12},
      {25, 17, 38, 12, 0}};

  int startCity = 0;
  travelingSalesman(graph, startCity);

  return 0;
}
