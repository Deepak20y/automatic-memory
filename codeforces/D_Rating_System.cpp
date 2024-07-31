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
    vector<ll>a(n),b(n);

    for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}

   

    for(int i=0;i<n-1;i++){b[i+1]+=b[i];}

  ll maxp=0;
 ll sum=0LL;
 ll ans=0LL;
 ll ans2=0LL;
  b[0]=max(b[0],0LL);
 for(int i=0;i<n-1;i++)
 {
        b[i+1]=max(b[i+1],b[i]);
 }

  //for(auto &x:b)cout<<x<<" ";cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
       sum+=a[i];
         if(i==0)
         {
              if(ans<max(sum,0LL)){ans=max(sum,0LL);ans2=0;}
         }
         else 
         {
            if(ans<b[i-1]+max(sum,0LL))
            {
                ans=max(sum,0LL)+b[i-1];
                ans2=b[i-1];
            }
         }

    }
   // cout<<ans<<endl;

    std::cout<<ans2<<endl;
        



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