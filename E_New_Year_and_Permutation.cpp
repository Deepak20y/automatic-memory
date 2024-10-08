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

  long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

 void solve(){
  ll n,m;
  cin>>n>>m;

  vector<int>fact(n+5);

  fact[0]=1LL;

   for(ll i=1;i<=n;i++)fact[i]=(fact[i-1]*(i))%m;
   
    ll pos=n; 
    ll ans=0LL;
    ll sp=1;
    for(int i=1;i<=n;i++)
    {    
          //cout<<pos<<" "<<fact[i]<<" "<<fact[n-sp]<<endl;

        ll mp=((((pos*fact[i])%m*fact[n-sp]))*(pos))%m;
           ans+=mp;


      sp++;
      pos--;
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