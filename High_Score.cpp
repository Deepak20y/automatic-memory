#include <stdio.h>
#include <limits.h>

#define INF INT_MAX // Infinity value

// Edge structure
struct Edge {
    int u, v, weight;
};

// Function to perform modified Bellman-Ford Algorithm to find maximum path
void bellmanFordMaxPath(int vertices, int edges, struct Edge edgeList[], int source) {
    // Distance array to store the longest distance from source to each vertex
    int dist[vertices];

    // Step 1: Initialize distances from source to all vertices as negative infinity, except source
    for (int i = 0; i < vertices; i++) {
        dist[i] = -INF;
    }
    dist[source] = 0;

    // Step 2: Relax all edges V-1 times (using negated weights)
    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeList[j].u;
            int v = edgeList[j].v;
            int weight = edgeList[j].weight;

            // Maximizing the path (finding the "longest" path)
            if (dist[u] != -INF && dist[u] + weight > dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for positive-weight cycles (which would make the maximum path unbounded)
    for (int i = 0; i < edges; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        int weight = edgeList[i].weight;

        if (dist[u] != -INF && dist[u] + weight > dist[v]) {
            printf("Graph contains a positive weight cycle, maximum path is unbounded\n");
            return;
        }
    }

    // Print the longest distances
    printf("Vertex\tLongest Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == -INF)
            printf("%d\t\t-INF\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int vertices = 5; // Number of vertices in graph
    int edges = 9; // Number of edges in graph

    // List of all edges in the graph (u, v, weight)
    struct Edge edgeList[] = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 3, 7}
    };

    int source = 0; // Starting node
    bellmanFordMaxPath(vertices, edges, edgeList, source);

    return 0;
}
