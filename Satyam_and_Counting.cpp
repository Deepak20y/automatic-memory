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
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
            a.push_back(x);
        else
            b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0LL;

    for (int i = 0; i < a.size(); i++)
    {

        if (binary_search(b.begin(), b.end(), a[i]))
        {
            ans += b.size() - 1;

            
        }
        if (binary_search(b.begin(), b.end(), a[i] - 1) && binary_search(b.begin(), b.end(), a[i] + 1))
                ans++;
    }

    for (int i = 0; i < b.size(); i++)
    {

        if (binary_search(a.begin(), a.end(), b[i]))
        {
            ans += a.size() - 1;

           
        }
         if (binary_search(a.begin(), a.end(), b[i] - 1) && binary_search(a.begin(), a.end(), b[i] + 1))
                ans++;
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