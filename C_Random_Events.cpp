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
       int m;cin>>m;

   vector<int>a(n);
   
     for(int i=0;i<n;i++)cin>>a[i];

       int ssp=n;
     for(int i=n-1;i>=0;i--)
     {
        if(ssp!=a[i])break;
        ssp--;
     }
 long double ans=1.0;
     for(int i=0;i<m;i++)
     {
         int mm;cin>>mm;
         long double p;cin>>p;
         if(mm>=ssp)ans*=(1.0-p);
     }
 // cout<<ssp<<endl;
 if(ssp==0){cout<<1.0<<endl;return;}



 long double sp=0.0;
  
   cout<<fixed<<setprecision(10)<<1.0-ans<<endl;




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