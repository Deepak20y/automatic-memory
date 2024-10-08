#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, mod = 1e9 + 7;
long long dp[N][N];
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] * i % mod;
        dp[i][1] = dp[i][0] * i % mod;
    }
    for (int j = 2; j <= n; j++)
        for (int i = 0; i <= n; i++)
            dp[i][j] = ((dp[i + 1][j - 2] * (j - 1)) % mod + (dp[i][j - 1] * i) % mod) % mod;

    int x = 0, y = 0;
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            vis[a[i]] = 1;
    for (int i = 0; i < n; i++)
    {
        if (vis[i + 1])
            continue;
        if (a[i] == -1)
            y++;
        else
            x++;
    }
  //  cout<<x<<" "<<y<<endl;
    cout << dp[x][y];
}