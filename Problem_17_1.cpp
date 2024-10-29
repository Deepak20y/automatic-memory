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
    map<int, int> c;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        if (q == 0)
        {
            a.push_back(p);
            c[p]++;
        }
        else
        {
            b.push_back(p);
            c[p]++;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    n=a.size();
    int m=b.size();
    for (int i = 0; i < n; i++)
    {

        if (binary_search(b.begin(), b.end(), a[i] - 1) && binary_search(b.begin(), b.end(), a[i] + 1))
            ans++;
    }

    for (int i = 0; i < m; i++)
    {

        if (binary_search(a.begin(), a.end(), b[i] - 1) && binary_search(a.begin(), a.end(), b[i] + 1))
            ans++;
    }

    for(auto &[x,y]:c)
    {
        if(y==2)ans+=n+m-2;
    }

    cout<<ans<<endl;

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