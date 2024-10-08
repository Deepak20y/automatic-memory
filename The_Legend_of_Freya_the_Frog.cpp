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
       
       ll x,y;cin>>x>>y;

       ll d;cin>>d;
     if(x%d==0)x/=d;
     else x=x/d+1;
       if(y%d==0)y/=d;
     else y=y/d+1;
 
   if(x==0&&y==0){cout<<0<<endl;return;}
  //cout<<x<<" "<<y<<endl;
  if(x==y)cout<<2*max(x,y)<<endl;
  else if(x>y)cout<<2*max(x,y)-1<<endl;
  else cout<<2*max(x,y)<<endl;



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