#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

 int dp[100004];

 void solve(){
         
         int n,k;
     cin>>n>>k;
      vector<int>a(n);
      for(int i=0;i<n;i++)cin>>a[i];

        for(int i=0;i<n;i++)
        dp[i]=1e9+5;

        dp[0]=0;
    // for(auto &x:a)cout<<x<<" ";cout<<endl;
    // cout<<n<<"="<<k<<endl;
     for(int i=0;i<n;i++)
     {
        for(int j=i+1;j<min(i+k+1,n);j++)
        { //cout<<i<<" "<<j<<endl;
            dp[j]=min(dp[j],dp[i]+abs(a[i]-a[j]));
        }
     }

     cout<<dp[n-1]<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}