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
      int n,m;cin>>n>>m; 
     vector<ll>b(m,0LL);

  string s;
  string t;
  cin>>s>>t;
  //cout<<s<<" "<<t<<endl;

  
   
   for(int i=m-1;i>=0;i--)
   {
     b[i]=t[i]-'0';
   }
   

   ll ans=0LL;
   reverse(s.begin(),s.end());
   reverse(b.begin(),b.end());
    ll sp=1LL;
    
    for(int i=m-1;i>=1;i--)b[i-1]+=b[i];



 
     int j=0;
    for(int i=0;i<n&&j<m;i++)
    {
        ll mp=s[i]-'0';

          ans+=(mp*b[j]*sp)%mod;
          ans%=mod;
    
         sp*=2LL;
         sp%=mod;
         j++;


    }

 cout<<ans;

  

  




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}