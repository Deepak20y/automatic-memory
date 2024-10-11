#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll maxp;
vector<pair<int,ll>> adj[300005];
vector<ll> c[300005];

void dfs(int node, ll sum, vector<ll>& a, int parent) {
    if (adj[node].size() == 1 && parent != -1) {
        c[node].push_back(0);
        return;
    }

    vector<ll> mp;
    mp.push_back(sum);

    for (auto &[x, y] : adj[node]) {
        if (x == parent) continue;

        
        dfs(x, max({-y + sum + a[node], -y + a[node], 0LL}), a, node);

        
        sort(c[x].begin(), c[x].end(), greater<ll>());

        c[node].push_back(max({c[x][0] - y + a[x], 0LL, -y + a[x]}));
        mp.push_back(c[node].back());
        sort(mp.begin(), mp.end(), greater<ll>());
        while (mp.size() > 2) mp.pop_back();

        if (c[node].size() > 2) {
            sort(c[node].begin(), c[node].end(), greater<ll>());
            c[node].pop_back();
        }
    }

    ll sp = 0LL;
    for (auto &x : mp) sp += max(x, 0LL);
    sp += a[node];
    maxp = max(maxp, sp);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    maxp = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxp = max(maxp, a[i]);
    }

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(0, 0, a, -1);

    cout << maxp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
