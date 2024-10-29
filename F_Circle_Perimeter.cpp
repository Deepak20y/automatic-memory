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
       ll r;cin>>r;
       
       ll ans=0LL;

       for(ll i=0;i<=r;i++)
       { 
         
          
        ll p=sqrt(r*r-i*i);
        if(i*i+p*p<r*r)p++;

        ll q=sqrt((r+1)*(r+1)-i*i);
        if(i*i+q*q>=(r+1)*(r+1))q--;

        if(p>q)continue;

        //cout<<i<<" "<<p<<" "<<q<<endl;

          if(i==0)
          { 
             if(p==0){ans++;ans+=2*q;}
             else {
                ans+=2*(p-q+1);
             }
            

          }
          else{
             
             if(p==0){ans+=2;p++;}

             if(p<=q)
             {
                 ans+=(q-p+1)*4;
             }
             


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