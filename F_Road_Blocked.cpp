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
vector<int> query[200005];
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int q;
    cin >> q;
    vector<vector<ll>> dist(n + 4, vector<ll>(n + 4, 1e17));

    vector<pair<int, pair<int, int>>> edge;

    for (int i = 0; i < m; i++)
    {
        int p, q, dis;
        cin >> p >> q >> dis;
        edge.push_back({p, {q, dis}});
    }
    vector<int> c;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;

        if (type == 2)
        {
            int p;
            cin >> p;
            query[i].push_back(p);
            cin >> p;
            query[i].push_back(p);
        }
        else
        {
            int p;
            cin >> p;
            p--;
            query[i].push_back(p);
            c.push_back(p);
        }
    }

    sort(c.begin(), c.end());

    int jjj = 0;
    for (int i = 0; i < m; i++)
    {
        if (jjj < c.size() && c[jjj] == i)
        {
            jjj++;
            continue;
        }

        dist[edge[i].first][edge[i].second.first] = edge[i].second.second;
        dist[edge[i].second.first][edge[i].first] = edge[i].second.second;
    }

    //  for(int i=1;i<=n;i++)
    //  for(int j=1;j<=n;j++)
    //  {
    //     cout<<dist[i][j]<<" ";
    //      if(j==n)cout<<endl;
    //  }
    // return;

    for (int i = 0; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
            {

                if (dist[i][k] < 1e17 && dist[k][j] < 1e17)
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }

    vector<ll> ans;

    for (int pp = q - 1; pp >= 0; pp--)
    {

        if (query[pp].size() == 2)
        {
            int p = query[pp][0];
            int sp = query[pp][1];

            if (dist[p][sp] == 1e17)
                ans.push_back(-1);
            else
                ans.push_back(dist[p][sp]);
        }
        else
        {

            auto [p, sp] = edge[query[pp][0]];

            if (dist[p][sp.first] > sp.second)
            {
                dist[p][sp.first] = sp.second;
                dist[sp.first][p] = sp.second;
            }

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {

                    if (dist[i][p] < 1e17 && dist[sp.first][j] < 1e17)
                        dist[i][j] = min(dist[i][j], dist[i][p] + dist[sp.first][j] + (ll)sp.second);
                }
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto &x : ans)
        cout << x << "\n";
    cout << endl;

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