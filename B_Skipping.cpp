#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

vector<vector<pair<int, ll>>> adj;
void solve()
{
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++)
    {
        adj[i].push_back({i - 1, 0});
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        adj[i].push_back({p, a[i]});
    }


    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

    q.push({0, 0});
    vector<ll> dist(n, 1e18);

    dist[0] = 0;

    while (!q.empty())
    {
        int p = q.top().second;
        q.pop();

        for (auto &[x, y] : adj[p])
        {
            if (dist[x] > dist[p] + y)
            {
                dist[x] = dist[p] + y;
                q.push({dist[x],x});
            }
        }
    }

  
    for (int i = 0; i < n - 1; i++)
    {
        a[i + 1] += a[i];
    }
    ll ans = a[0];
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] - dist[i]);
    }

    cout << ans << "\n";

    adj.clear();

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
    return 0;
}