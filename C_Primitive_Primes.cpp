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
       int p;cin>>p;

       vector<pair<int,int>>a,b;

       for(int i=0;i<n;i++)
       {
         int t;cin>>t;
          t%=p;

          if(t!=0)
          {
            a.push_back({t,i});
          }
       }

     for(int i=0;i<m;i++)
       {
         int t;cin>>t;
          t%=p;

          if(t!=0)
          {
            b.push_back({t,i});
          }
       }

     
map<ll,int>c;

 for(int i=0;i<a.size();i++)
 {
    for(int j=0;j<b.size();j++)
    {
        c[a[i].second+b[i].second]= (c[a[i].second+b[i].second]+a[i].first+b[i].first)%p;
        
    }
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