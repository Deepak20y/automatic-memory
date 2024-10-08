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
        ll n,s,m;
        cin>>n>>s>>m;

  ll maxp=0LL;
  vector<pair<ll,ll>>a(n);
   for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    
    
     maxp=max(a[0].first,maxp);
     maxp=max(m-a[n-1].second,maxp);

     for(int i=1;i<n;i++)
     {
        maxp=max(a[i].first-a[i-1].second,maxp);

     }

     if(maxp>=s)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;



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