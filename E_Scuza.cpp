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
    int q;
    cin >> q;
    vector<ll> a(n);
    vector<ll> b(n);
    int minp = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        minp = min((int)a[i], minp);
    }

    set<pair<ll, ll>> c;

    for (int i = 0; i < n - 1; i++)
    {
        b[i + 1] += b[i];
    }
      int p=a[0];
      c.insert({a[0],0});
   for(int i=1;i<n;i++)
   {  
       if(p<=a[i])
       {
         c.insert({a[i],i});
         p=max(p,(int)a[i]);
       }
     
   }



    while (q--)
    {
        int k;
        cin >> k;
        auto st=c.begin();
        if (k < minp||k<st->first)
        {
            cout << 0 << " ";
            continue;
        }

        st = c.upper_bound({k, 3e5});

        if (st == c.end())
        {
            cout << b[n - 1] << " ";
        }
        else
        {

            int p = st->second;
            p--;

            cout << b[p] << " ";
        }
    }

    cout << endl;

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