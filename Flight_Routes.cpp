#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

vector<pair<int, ll>> adj[100005];
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
   // cout<<n<<" "<<m<<" "<<k<<endl;

    set<pair<int, int>> a;

    for (int i = 0; i < m; i++)
    {
        int p, q, cost;
        cin >> p >> q >> cost;
        adj[--p].push_back({--q, cost});
    }

    a.insert({0, 0});
    vector<ll> dist(n, 1e17);
    dist[0] = 0;
    multiset<ll> ans;
    while (!a.empty())
    {
        auto p = a.begin();
        int q = p->second;
        a.erase(p);

        for (auto &[x, y] : adj[q])
        {   //cout<<x<<" ";
            if (x == n - 1)
                ans.insert(dist[q] + y);

            if (dist[x] > dist[q] + y)
            {
                dist[x] = dist[q] + y;
                a.insert({dist[x], x});
            }
        }
    }

    for (auto &x : ans)
    {
        cout << x << " ";
        k--;
        if (k == 0)
            break;
    }

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}