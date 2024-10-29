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
       ll a[n+5][n+5];

       for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       {cin>>a[i][j];}

  
  ll ans=0LL;
  for(int i=2;i<=n;i++)
  {
        int p=i;
        int t=1;
         ll st=1e9;
        while(p<=n&&t<=n)
        {
          st=min(a[p][t],st);
          p++;t++;
        }
        if(st<0)ans-=st;
        
  }

   for(int i=1;i<=n;i++)
  {
        int p=1;
        int t=i;
         ll st=1e9;
        while(p<=n&&t<=n)
        {
          st=min(a[p][t],st);
          p++;t++;
        }
        if(st<0)ans-=st;
        
  }


  

cout<<ans<<endl;
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