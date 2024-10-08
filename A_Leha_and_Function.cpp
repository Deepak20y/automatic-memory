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
       vector<pair<int,int>>a(n);

     vector<int>b(n);

     for(int i=0;i<n;i++)cin>>b[i];


      for(int i=0;i<n;i++)
      {
         cin>>a[i].first;
         a[i].second=i;
      }
      sort(b.begin(),b.end(),greater<int>());
      sort(a.begin(),a.end());
         vector<int>ans(n);
      for(int i=0;i<n;i++)
      {
           ans[a[i].second]=b[i];
      }

      for(auto &x:ans)cout<<x<<" ";cout<<endl;

      






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}