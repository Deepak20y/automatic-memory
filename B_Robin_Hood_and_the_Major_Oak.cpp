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
    
    ll n,k;
    cin>>n>>k;

  
     
     ll p=n-k+1;

        
        if(p==n)
        {
          if(p%2==0)cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
          
          return;
        }
     
      if(p%2==0)p++;
  

      p=(n-p)/2+1;
      p=max(0LL,p);

      

      if(p%2==0)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;





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