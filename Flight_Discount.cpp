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
    int m;
    cin >> m;
 
    adj.resize(n);
 
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;
        int distance;
 
        cin >> distance;
        if (p == q)
            continue;
        adj[--p].push_back({--q, distance});
    }
 
    auto cmp = [&](const pair<ll, ll> &a, const pair<ll, ll> &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    };
 
 
    //priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> a(cmp);
    set<pair<ll,ll>,decltype(cmp)>a(cmp);
    vector<vector<ll>> distance(n + 1, vector<ll>(2, LLONG_MAX));
    a.insert({0LL, 0LL});
    distance[0][0] = 0;
 
    while (!a.empty())
    {
        int code = a.begin()->first;
        ll node = a.begin()->second;
        a.erase(a.begin());
        if(n-1==node)break;
        if(code/2>distance[node][code%2])continue;
 
        if (code % 2 == 0)
        {
            for (auto &[x, y] : adj[node])
            {
                if (distance[x][1] > distance[node][0] + y / 2LL)
                {
                    distance[x][1] = distance[node][0] + y / 2LL;
                    a.insert({2LL * (distance[x][0] + y / 2) + 1LL, x});
                }
 
                if (distance[x][0] > distance[node][0] + y)
                {
                    distance[x][0] = distance[node][0] + y;
                    a.insert({2LL * (distance[x][0] + y), x});
                }
            }
        }
        else
        {
            for (auto &[x, y] : adj[node])
            {
                if (distance[x][1] > distance[node][1] + y)
                {
                    distance[x][1] = distance[node][1] + y;
                    a.insert({2LL * (distance[x][1] + y) + 1LL, x});
                }
            }
        }
    }
 
    cout << min(distance[n - 1][1], distance[n - 1][0]) << endl;
 
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