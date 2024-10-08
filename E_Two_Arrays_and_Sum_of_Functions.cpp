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
const int mod=998244353;
 void solve(){
       int n;cin>>n;
       vector<ll>a(n);
       for(int i=0;i<n;i++)
       {
        cin>>a[i];
       }

        vector<ll>b(n);

        for(int i=0;i<n;i++)cin>>b[i];


        for(int i=0;i<n;i++)
        {
           ll p=i+1;
           ll mp=n-i;
           a[i]*=mp*p;


        }
  sort(a.begin(),a.end());

   sort(b.begin(),b.end(),greater<ll>());

  ll ans=0LL;

    for(int i=0;i<n;i++)
    {
        ans+=(a[i]%mod*b[i])%mod;
        ans%=mod;
    }
      

        cout<<ans<<endl;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}