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
    vector<ll> a(n);
    map<int, int> b;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = n;
    int maxp = a[n - 1];

    int minp = a[0];

    if (a[0] + a[1] > a[n - 1])
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        b[a[i]] = i;
    }

    for (int i = 0; i < n-2; i++)
    {
        int cnt = 1;
        int j = i;
      

        int up = upper_bound(a.begin(), a.end(), a[i]+a[i+1]-1) - a.begin();
         int sup = upper_bound(a.begin(), a.end(), 2*a[i]-1) - a.begin();
      




        up = n - up;
        ans = min(ans, j + up);
        sup=n-sup;
        ans=min(ans,j+sup);
    }

    ans=max(ans,0);

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