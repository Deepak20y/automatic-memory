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
// yeah that's how i will do it
// dp[i][j] is that numeber of times j th element can be formed with the first i elements and
// then i will include i+1 in the list
const int mod = 998244353;
vector<vector<ll>> dp;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    dp.assign(n+4, vector<ll>(5005, 0LL));

    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = 1;
    dp[0][0]=1;
 
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 5000; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if (j >= a[i - 1])
            {
                dp[i][j] += dp[i - 1][j - a[i - 1]];
            }

            dp[i][j] %= mod;
        }
 ll ans=0LL;
    ans+=a[0];

    for (int i = 2; i <=n; i++)
    {   ans+=a[i-1];
         for(int j=1;j<=5000;j++)
         {
               ll st=dp[i-1][j];
               if(st>0)
               {
                   if(j>=a[i-1])ans+=((j+a[i-1])/2+(j+a[i-1])%2)*dp[i-1][j];
                   else ans+=a[i-1]*dp[i-1][j];
               }

               ans%=mod;

         }

    }

    cout<<ans;
        


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