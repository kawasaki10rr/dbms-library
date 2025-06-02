#include <stdio.h>

#define MAX 30
#define INF 99
int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int union_sets(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, i, j, u, v, a, b, min, ne = 1;
    int cost[MAX][MAX], total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (99 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    while (ne < n) {
        min = INF;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (union_sets(u, v)) {
            printf("Edge %d: (%d - %d) Cost = %d\n", ne++, a, b, min);
            total += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum cost = %d\n", total);
    return 0;
}

/*
99  10  6  99
10  99  5   15
6   5   99  4
99  15  4   99
*/