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
ll dp[404][404];
// it is possible to optimize it with knuth optimization into n^2 dp
void solve()
{

    int n;
    cin >> n;
    vector<ll> a(n);
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // for (auto &x : a)
    //     cout << x << " ";
    // cout << endl;

    for (int i = 0; i < n - 1; i++)
    {

        dp[i][i + 1] = a[i] + a[i + 1];
    }

    for (int i = 0; i < n - 1; i++)
        a[i + 1] += a[i];

    for (int i = 2; i < n; i++)
    {

        for (int j = 0; j + i < n; j++)
        {
            int start = j;
            int end = j + i;

            ll best = 1e17;
            ll sump = a[end];
            if (start != 0)
                sump -= a[j - 1];
            for (int k = start; k < end; k++)
            {
                best = min(best, dp[start][k] + dp[k + 1][end] + sump);
            }

            dp[start][end] = best;
        }
    }

    cout << dp[0][n - 1] << endl;

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