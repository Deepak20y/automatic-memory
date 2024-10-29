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
 
 const int mod=1e9+7;

 long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

 void solve(){
       ll l,r,k;
       cin>>l>>r>>k;
  ll sp=0LL;
         
         if(k==1)
         {
            cout<<(binpow(10,r)-binpow(10,l)+mod)%mod<<endl;
         }
         else if(k==2)
         {

          cout<<(binpow(5,r)-binpow(5,l)+mod)%mod<<endl;

         }
         else if(k==3)
         {
         
            sp=binpow(4,l);
          
            cout<<(binpow(4,r)-sp+mod)%mod<<endl;
         }
         else if(k==4)
         {  
             
            sp=binpow(3,l);
          
            cout<<(binpow(3,r)-sp+mod)%mod<<endl;

         }
         else if(k<=9)
         {  
          
            sp=binpow(2,l);
            cout<<(binpow(2,r)-sp+mod)%mod<<endl;
         }
         else cout<<0<<endl;






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}