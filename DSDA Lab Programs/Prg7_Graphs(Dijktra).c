#include <stdio.h>
int main()
{
 int n, v, count = 1, distance[100], visited[100], 
 cost[100][100], i, j, weight, choice, min, source;
 printf("enter the vertices:\n");
 scanf("%d", &n);
 printf("entre the cost matrix:\n");
 for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
     {
      scanf("%d", &cost[i][j]);
     }
  }
 for (i = 0; i < n; i++)
  {
   for (j = 0; j < n; j++)
    {
     if (i == j || cost[i][j] == 0)
      {
       cost[i][j] = 999;
      }
    }
  }
 
printf("enter the source vertex:");
scanf("%d", &source);
for (i = 0; i < n; i++)
 {
  visited[i] = 0;
  distance[i] = cost[source][i];
 }

visited[source] = 1;
distance[i] = 0;
printf("\n");
 
while (count < n - 1)
 {
   min = 999;
   for (i = 0; i < n; i++)
   {
    if (cost[source][i] < min && !visited[i])
     {
      min = cost[source][i];
      v = i;
     }
   }
 visited[v] = 1;
 for (i = 0; i < n; i++)
  {
   if (!visited[i])
    {
     if (distance[i] > min + cost[v][i])
      {
       distance[i] = min + cost[v][i];
      }
    }
  }
 count++;
 }
 for (i = 0; i < n; i++)
  {
   if (i != source)
    {
     printf("the shortest distance from %d to %d is %d\n", source, i, distance[i]);
    }
  }
 return 0;
}