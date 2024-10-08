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
       

      ll x,y;
      cin>>x>>y;
     x=gcd(x,y);
     vector<ll>a(n);
      for(int i=0;i<n;i++)
      { 
         cin>>a[i];
         a[i]%=x;
      }

      sort(a.begin(),a.end());
      
    set<ll>b;
    for(int i=0;i<n;i++)b.insert(a[i]);

    if(b.size()==1)cout<<0<<endl;
    else{

        int m=b.size();
        ll ans=1e9;
        for(int i=0;i<=m;i++)
        { 
            ll p=*b.begin();
            b.erase(b.begin());
          auto  sp=b.end();
           sp--;
           ans=min(ans,abs(p-*sp));
           b.insert(x+p);

        } 

        cout<<ans<<endl;

    }



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