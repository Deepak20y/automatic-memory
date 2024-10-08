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

 ll minp;
 ll ans;
bool ok(ll mid,ll a,ll b)
{     
    ll p=(a*(a-1))/2LL;

        ll sp=(mid*(mid+1))/2LL;
        ll tp=(b*(b+1))/2LL;

 
        tp-=sp;
        sp-=p;
    // cout<<mid<<" "<<sp<<" "<<tp<<endl;
         if(sp<=tp)
         {
             ans=min(ans,abs(sp-tp));
            return true;
         }
         else
         {
             ans=min(ans,abs(sp-tp));
             return false;
         }





}
 
 void solve(){
       
       minp=1e17;
       int a,b;cin>>b>>a;
         b=a+b-1;
       ll low=a;
       ll high=b;
        
          ans=1e18;
        
       ll mid;

       for(int i=0;i<50;i++)
       {
          if(high>=low)
          {
               mid=(high+low)/2;

               if(ok(mid,a,b))low=mid;
               else high=mid;
          }

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