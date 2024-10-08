#include<bits/stdc++.h>
using namespace std;
using ll =long double;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

// vector<ll>a;
//   ll recur(int i,int n,int cnt)
//  {
//      if(i>=n)
//      {   cout<<(n-cnt>cnt)<<endl;
//          if(n-cnt>cnt)return 1.0;
//          else return 0;

//      }
//      ll ans=0.0;

//      ans=recur(i+1,n,cnt+1)*a[i]+recur(i+1,n,cnt)*(1.0-a[i]);

//      return ans;


//  }
 void solve(){
        int n;cin>>n;

   vector<ll>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
 
   vector<vector<ll>>dp(n+3,vector<ll>(n+3,0.0));


   dp[1][1]=a[0];
   dp[1][0]=1.0-a[0];


   for(int i=2;i<=n;i++)
   {  
         dp[i][0]=dp[i-1][0]*(1.0-a[i-1]);

      for(int j=1;j<=i;j++)
      {
         dp[i][j]=dp[i-1][j]*((ll)1.0-a[i-1])+dp[i-1][j-1]*a[i-1];
      }

   }

   ll ans=0.0;
   

   for(int i=1;i<=n;i++)
   {
       if(i>n-i)ans+=dp[n][i];

   }

   cout<<setprecision(15)<<ans<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}