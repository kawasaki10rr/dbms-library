#include <stdio.h>
#define MAX 10
#define INF 99

int main() {
    int cost[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int n, i, j, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (99 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
    }
    visited[src] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}

/*
Enter number of vertices: 5
Enter cost adjacency matrix (99 for no edge):
0  10  3  99 99
10 0  1  2  99
3  1  0  8  2
99 2  8  0  7
99 99 2  7  0
Enter source vertex: 0

*/