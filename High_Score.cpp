#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

const long long NEG_INF = -1e18;

struct Edge {
    int u, v;
    long long weight;
};

int n, m;
vector<Edge> edges;
vector<vector<int>> adj, rev_adj;

vector<long long> bellmanFord(int start) {
    vector<long long> dist(n + 1, NEG_INF);
    dist[start] = 0;

    // Bellman-Ford relaxation for (n - 1) times
    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != NEG_INF && dist[edge.u] + edge.weight > dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for cycles by relaxing one more time
    vector<bool> inCycle(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != NEG_INF && dist[edge.u] + edge.weight > dist[edge.v]) {
                inCycle[edge.v] = true;
            }
        }
    }

    // Mark all nodes that are reachable from any cycle node
    queue<int> q;
    vector<bool> reachableFromCycle(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (inCycle[i]) {
            q.push(i);
            reachableFromCycle[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!reachableFromCycle[v]) {
                reachableFromCycle[v] = true;
                q.push(v);
            }
        }
    }

    // Check if any cycle node can reach room n
    if (reachableFromCycle[n]) {
        cout << -1 << endl;
        return {};
    }

    return dist;
}

int main() {
    cin >> n >> m;
    edges.resize(m);
    adj.resize(n + 1);
    rev_adj.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        edges[i] = {a, b, x};
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    vector<long long> dist = bellmanFord(1);
    if (!dist.empty()) {
        cout << dist[n] << endl;
    }

    return 0;
}
