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

 void solve(){
       int n;cin>>n;
       
       string s;cin>>s;
       vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];

        vector<vector<ll>>dp(n+3,vector<ll>(5,0));


      for(int i=0;i<n;i++)
      {
           if(i!=0)
           {
             dp[i][0]=dp[i-1][0];
              dp[i][1]=dp[i-1][1];
               dp[i][2]=dp[i-1][2];
                dp[i][3]=dp[i-1][3];
           }


           if(s[i]=='h')dp[i][0]+=a[i];
           else if(s[i]=='a')dp[i][1]=min(dp[i][1]+a[i],dp[i][0]);
           else if(s[i]=='r')dp[i][2]=min(dp[i][2]+a[i],dp[i][1]);
           else if(s[i]=='d')dp[i][3]=min(dp[i][3]+a[i],dp[i][2]);

      }


      cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2],dp[n-1][3]})<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}