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
string s;
vector<int> adj[200005];
vector<int> vis;
vector<int> ans;
vector<int> vis2;

bool dfs(int sn, int cnt)
{
    vis2[sn] = 1;
    vis[sn] = 1;
    if (s[sn - 1] == '0')
    {
        cnt++;
    }
    bool ok = false;
    for (auto i : adj[sn])
    {
        if (!vis[i])
        {
            ok= dfs(i, cnt);
            ans[sn] = ans[i];
            if (!ok)
            {
                if (s[sn - 1] == '0')
                    ans[sn]++;
            }
            else if (ok)
            {
                return true;
            }
        }
        else if (vis2[i])
        {
            ans[sn] = cnt;
            vis2[sn] = 0;
            return true;
        }
        else
        {
            ans[sn] += ans[i];
        }
    }
    vis2[sn] = 0;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    ans.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    vis2.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        adj[i].push_back(m);
    }

    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 0);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout <<'\n';

    for (int i = 1; i <= n; i++)
        adj[i].clear();

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