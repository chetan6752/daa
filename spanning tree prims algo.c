//[5] SPANNING TREE USING PRIMS ALGO

#include <stdio.h>
#include <limits.h>
#define MAX 100

int main() {
    int n, cost[MAX][MAX];
    int selected[MAX] = {0}, no_edge = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // no edge represented as infinity
        }
    selected[0] = 1;  // start from vertex 0

    printf("Edges in MST:\n");
    while (no_edge < n - 1) {
        int min = INT_MAX, x = 0, y = 0;
        for (int i = 0; i < n; i++)
            if (selected[i])
                for (int j = 0; j < n; j++)
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
        printf("%d - %d : %d\n", x, y, cost[x][y]);
        selected[y] = 1;
        no_edge++;
    }
    return 0;
}
