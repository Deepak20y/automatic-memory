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

void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[n + 5][m + 5];
    ll ans = 0LL;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int j = 0; j < m; j++)
    {
        vector<ll> b(n);
        for (int i = 0; i < n; i++)
            b[i] = a[i][j];

        sort(b.begin(), b.end());

        for (int i = 0; i < n - 1; i++)
        {
            b[i + 1] += b[i];
        }

        for (int i = 1; i < n; i++)
        {
            ans += (b[i] - b[i - 1]) * (ll)i - b[i - 1];
        }
    }
    cout << ans << endl;

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