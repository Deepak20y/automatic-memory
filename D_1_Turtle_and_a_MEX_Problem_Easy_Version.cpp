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
    int kpp;
    cin >> kpp;
    ll maxp = 0LL;

    vector<vector<int>> a;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> b;
        int m;
        cin >> m;
    
         int sp=0;
        for (int i = 0; i < m; i++)
        { int lp;
            cin >> lp;
            b.push_back(lp);
            sp++;
        }
        a.push_back(b);

        cnt=max(cnt,sp);
    }
   cnt+=4;
   set<int>ee;
    //int maxpp=0;
    for (int i = 0; i < n; i++)
    {
        set<int> d;
        for (int j =0;j<a[i].size(); j++)
        {
            d.insert(a[i][j]);
        }

        //for(auto &x:d)cout<<x<<" ";cout<<endl;

        vector<int> pp;
        for (int j = 0; i <= a[i].size()+1; j++)
        {
            if (d.find(j) == d.end())
                pp.push_back(j);

            if (pp.size() == 2)
                break;
        } 
        
          maxp=max((ll)pp[0],maxp);
          maxp=max((ll)pp[1],maxp);
        
        
    }

    ll ans = 0LL;
    ans+=maxp*(maxp+1);
  
 // cout<<endl;
   cout<<maxp<<" "<<ans<<endl;

    if (maxp < kpp)
    {
        ll lp = kpp;

        lp = ((lp + 1LL) * lp) / 2LL;

        ll tp = maxp;
        tp = ((tp + 1LL) * tp) / 2LL;

        ans += lp - tp;
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