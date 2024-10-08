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

ll dp[200005];
const int mod=1e9+7;

 void fill()
{

    dp[0]=1LL;

    for(ll i=1;i<=200000;i++)
    {
        dp[i]=(i*dp[i-1])%mod;
    }

    for(int i=1;i<=200000;i++){dp[i]*=dp[i-1];dp[i]%=mod;}
  //  cout<<dp[5]<<endl;
}

long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

 void solve(){
        ll n;cin>>n;
        ll k;cin>>k;
        ll cnt1=0,cnt0=0;
   vector<ll>dp2(n+5,0LL),dp1(n+5,0LL);
        for(int i=0;i<n;i++)
        {
            int m;cin>>m;
            if(m==1)cnt1++;
            else cnt0++;
        }

       
       
 ll ans=0LL;

   for(int i=1;i<=cnt1;i++)
   {
     dp1[i]=((dp[cnt1]*inv(dp[cnt1-i],mod))%mod*inv(i,mod))%mod;
   }


  dp2[0]=1LL;

 for(int i=1;i<=cnt0;i++)
 { 
     dp2[i]=((dp[cnt0]*inv(dp[cnt0-i],mod))%mod*inv(i,mod))%mod;
 }

 for(int i=(k+1)/2;i<=min(cnt1,k);i++)
 {
     int p=k-i;
   cout<<i<<" "<<p<<" "<<dp1[i]<<" "<<dp2[p]<<endl;
      if(cnt1<i||cnt0<p)continue;
  
      ans+=(dp1[i]*dp2[p])%mod;
     ans%=mod;
 }

 cout<<ans<<endl;



 








return;
}
int main()
{
    fill();
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}