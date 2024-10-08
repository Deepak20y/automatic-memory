#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;
const ll INF = 1e16;
// for dense graph use floy warshall
ll dist[505][505];

void floydWarshall(int n) {
    // Implementing Floyd-Warshall algorithm
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {  // To avoid overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    // Initialize the distance matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // Input edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);  // If the graph is undirected
    }

    // Run Floyd-Warshall algorithm
    floydWarshall(n);

    // Answer queries
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (dist[u][v] == INF) {
            printf("-1\n");
        } else {
            printf("%lld\n", dist[u][v]);
        }
    }
}

int main() {
    solve();
    return 0;
}
