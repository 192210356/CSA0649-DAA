#include <stdio.h>

#define V 5 // number of vertices

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

void union_set(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot]) parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal(int cost[][V]) {
    int parent[V], rank[V];
    int i, j, k = 0;
    int min_cost = 0;
    int edges[V * (V - 1) / 2];

    // Initialize parent and rank arrays
    for (i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Create a list of edges
    k = 0;
    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            edges[k].u = i;
            edges[k].v = j;
            edges[k].cost = cost[i][j];
            k++;
        }
    }

    // Sort edges in non-decreasing order of cost
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
            if (edges[i].cost > edges[j].cost) {
                int temp = edges[i].cost;
                edges[i].cost = edges[j].cost;
                edges[j].cost = temp;
            }
        }
    }

    // Select edges using Kruskal's algorithm
    for (i = 0; i < k; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);
        if (x!= y) {
            union_set(parent, rank, x, y);
            printf("Edge %d-%d has cost %d\n", edges[i].u, edges[i].v, edges[i].cost);
            min_cost += edges[i].cost;
        }
    }

    printf("Minimum cost = %d\n", min_cost);
}

int main() {
    int cost[][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    kruskal(cost);

    return 0;
}
