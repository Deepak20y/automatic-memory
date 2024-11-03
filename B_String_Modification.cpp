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
    string s;
    cin >> s;

    string ans = s;

    int k = 1;

    for (int j = 2; j <= n - 1; j++)
    {

        string p = "";

        for (int i = j - 1; i < n; i++)
        {
            p.push_back(s[i]);
        }
        
        int m = n - j - 1;
        if (m % 2 == 0)
        {
            for (int i = 0; i < j - 1; i++)
                p.push_back(s[i]);
        }
        else
        {

            for (int i = j - 2; i >= 0; i--)
                p.push_back(s[i]);
        }

        if (ans > p)
        {
            ans = p;
            k = j;
        }
        
    }

    reverse(s.begin(), s.end());

    if (ans > s)
    {
        ans = s;
        k = n;
    }

    cout << ans << "\n"
         << k << "\n";

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