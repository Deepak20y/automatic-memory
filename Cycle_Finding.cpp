#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Edge {
    int a, b;
    ll cost;
};

int n, m;
vector<Edge> edges;
const ll INF = 1e17;

void solve() {
    cin >> n >> m;

    edges.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
        edges[i].a--;
        edges[i].b--;
    }

    vector<ll> d(n, INF);
    vector<int> p(n, -1);
    int x = -1;

    d[0] = 0;

  
    // Check if there's a negative cycle detected
    if (x == -1) {
        cout << "NO\n";
    } else {
        // Identify the start of the cycle by moving `x` n steps back
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
            cout << v + 1 << ' ';
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
