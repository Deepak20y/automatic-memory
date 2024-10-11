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
int dp[102][1 << 17];

pair<int, int> path[102][1 << 17];
void solve()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b;

    for (int i = 2; i <= 60; i++)
    {
        int p = i;
        bool ok = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
                ok = false;
        }

        if (ok)
            b.push_back(i);
    }

    vector<vector<int>> c;
    vector<int> ff;
    ff.push_back(0);
    c.push_back(ff);

    for (int i = 1; i <= 60; i++)
    {
        vector<int> d;
        int p = i;
        for (int j = 2; j * j <= p; j++)
        {
            if (p % j == 0)
                d.push_back(j);
            while (p % j == 0)
                p /= j;
        }

        if (p > 1)
            d.push_back(p);
        c.push_back(d);
    }

    map<int, int> aa;

    for (int i = 0; i < 17; i++)
    {
        aa[b[i]] = i;
    }
    memset(dp, -1, sizeof(dp));
    //  for (int i = 0; i < 31; i++)
    for (int j = 0; j <= (1 << 17); j++)
        dp[0][j] = 0;

    vector<int> e;
    e.push_back(0);
    e.push_back(0);

    for (int i = 2; i <= 60; i++)
    {
        int p = 0;
        for (auto &x : c[i])
        {
            p = p | (1 << aa[x]);
        }
        e.push_back(p);
    }

    
    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j <= 60; j++)
        {
            // if(dp[i][e[j]]==1e9)continue;
            for (int k = 0; k < (1 << 17); k++)
            {
                if (j != 1 && (e[j] & k) == 0 && dp[i][e[j]] != -1)
                {
                    
                    if (dp[i + 1][e[j] | k] == -1)
                    {
                        dp[i + 1][e[j] | k] = dp[i][k] + abs(a[i] - j);
                        path[i + 1][e[j] | k] = {k, j};
                    }
                    else
                    {   
                         if(dp[i+1][e[j]|k]>dp[i][k]+abs(a[i]-j))
                         {
                            dp[i + 1][e[j] | k] = dp[i][k] + abs(a[i] - j);
                            path[i + 1][e[j] | k] = {k, j};
                         }
                       

                        
                    }
                }
                else if (j == 1)
                   { dp[i + 1][k] = dp[i][k] + abs(a[i] - 1);
                   path[i + 1][k] = {k, j};

            }
            }
        }
    }
  int maxp=1e9;
  int idx=0;
    for (int i = 0; i < (1 << 17); i++)
    {   
        if(dp[n][i]<maxp)
        {
            maxp=dp[n][i];
            idx=i;
            
        }
    }
    int j=n;
    vector<int>ans;
    while(j>0)
    {   ans.push_back(path[j][idx].second);
        idx=path[j][idx].first;
        j--;

    }

    reverse(ans.begin(),ans.end());
    for(auto &x:ans)cout<<x<<" ";

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