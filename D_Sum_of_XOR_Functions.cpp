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

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    ll ans = 0LL;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i <= 30; i++)
    {
        ll cnt0 = 1LL;
        ll cnt1 = 0LL;
        ll sum0 = 0LL;
        ll sum1 = 0LL;
        bool ok=false;
        ll sp = 0LL;
        for (int j = 1; j <= n; j++)
        {
            if ((1 << i) & a[j])
                ok=!ok;


            if (ok)
            {
                cnt1++;
                sum1 += j;
                sp += cnt0 * (ll)(j) - sum0;
            }
            else
            {
                cnt0++;
                sum0 += j;

                sp += cnt1 * (ll)(j) - sum1;
            }

            sp %= mod;
             // cout<<cnt0<<" "<<cnt1<<" "<<sum0<<" "<<sum1<<" "<<sp<<endl;
           
        }
      
      
        ll mp = (1 << i);
          //cout<<sp<<" "<<mp<<endl;
        ans += (sp * mp) % mod;
        ans%=mod;
    }

    cout << ans;

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