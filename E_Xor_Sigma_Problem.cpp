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
        bool ok=false;
        queue<pair<int,int>>q;
        if((1<<i)&a[1]){ok=true;q.push({1,1});}
        else q.push({0,1});
        ll sp = 0LL;
        for (int j = 2; j <= n; j++)
        {
            if ((1 << i) & a[j])
                ok=!ok;

           
            if (ok)
            {
                q.push({1,j});
                sp += cnt0;
            }
            else
            {
                q.push({0,j});
              
                sp += cnt1;
            }
               
             // cout<<q.front().first<<" "<<q.front().second<<endl;
            
            while(!q.empty())
            {
               if(j-q.front().second>=1)
               {
                   if(q.front().first==1)cnt1++;
                   else cnt0++;
                   q.pop();
               }
               else break;

            }
          
           
        }
       
      // cout<<endl;
      
        ll mp = (1 << i);
       // cout<<mp<<" "<<sp<<" "<<cnt1<<" "<<cnt0<<endl;
          //cout<<sp<<" "<<mp<<endl;
        ans += (sp * mp);
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