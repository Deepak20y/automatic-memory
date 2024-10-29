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
       int n;
       cin>>n;
       ll k;cin>>k;
  
   vector<ll>a(n);
 
   for(int i=0;i<n;i++)
   {

     cin>>a[i];
   }
 
   if(n==1)
   { 
     cout<<a[0]<<endl;
   }
   else{
       
        if(k>=3){cout<<0<<endl;return;}
         vector<ll>b;
         set<ll>c;
          sort(a.begin(),a.end());
              ll minp=a[0];
              for(int i=0;i<n;i++){minp=min(minp,a[i]);
              c.insert(a[i]);
               }

              for(int i=0;i<n;i++)
              for(int j=i+1;j<n-1;j++)
              {
                 minp=min(minp,a[j]-a[i]);
                 c.insert(a[i]);
              }

              if(k==1)
              {
                cout<<minp<<endl;return;
              }
             
             vector<ll>d;

             for(auto &x:c)
             {
                d.push_back(x);
             }

             n=d.size();

             for(int i=0;i<n-1;i++)
             {
                 minp=min(minp,a[i+1]-a[i]);

             }

             cout<<minp<<endl;
              
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