#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

vector<vector<int>> adj;
vector<int> dist;
vector<bool> vis;
vector<int>anss;

void solve()
{
    int n;
    cin >> n;

    adj.assign(n + 1, vector<int>());
    dist.assign(n + 1, 0);
    vis.assign(n + 1, false);
    anss.assign(n+1,0);

    for (int i = 1; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

     int ans=adj[1].size();

    while (!q.empty())
    {
        int p = q.front();
        q.pop();


    
        for (auto &x : adj[p])
        {
            if (vis[x])
                continue;
            vis[x] = true;
            dist[x] = dist[p] + 1;
            q.push(x);
        }
    }

    int maxp = 0;
    bool ok = true;
    map<int,int>b;
    int minp=1e9;
 
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            if (maxp == 0)
            {
                maxp = dist[i];
            }
            else if (dist[i] != maxp)
            {
                ok = false;
            }
            minp=min(minp,dist[i]);
        }
        b[dist[i]]++;
    }

    if (ok)
    {
        cout << 0 << endl;
        return;
    }


    for(int i=x+1;i<=1;i++)


 
 



    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
