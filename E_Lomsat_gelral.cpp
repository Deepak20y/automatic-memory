#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

vector<int> adj[200005];

const int MX = 2e5;

struct DSU {
    int p[MX + 1];
    ll sum[MX + 1];

    
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    }

    set<pair<int, int>, decltype(&cmp)> elements[MX + 1] = {set<pair<int, int>, decltype(&cmp)>(cmp)};

  
    void make_set(int u) {
        p[u] = u;
        elements[u].insert({1, u});
        sum[u] = u;
    }

    int find(int u) {
       
        return p[u];
    }


    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (elements[u].size() > elements[v].size()) {
                swap(u, v);
            }
       int maxp=max(elements[u].begin()->second,elements[v].begin()->second);
            ll sum=0LL;
            while (!elements[u].empty()) {
                pair<int, int> x = *elements[u].begin();
                
                auto sp=elements[v].find(x);
                if(sp!=elements[v].end())
                {
                    pair<int,int> y=*sp;
                    sp=elements[v].end();
                    elements[u].erase(elements[v2].begin());


                }
                else 
                {
                  
                  elements[v].insert(x);

                }
                
                p[u] = v;
                elements[u].erase(elements[u].begin());
            }
        }
    }
} dsu;

vector<int> a;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dsu.make_set(i);
    }

    a.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Additional code for your problem would go here

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
