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
       vector<int>a(n+1);
    
        ll sum=0;
       for(int i=0;i<n+1;i++){cin>>a[i];sum+=a[i];}
           int p=a[n];
    ll ans=1e9;

    sort(a.begin(),a.end());
    ans=sum-p;
  //cout<<ans<<endl;
 // for(auto &x:a)cout<<x<<" ";cout<<endl;
    while(true)
    {
       int prev=p;
       int sp=upper_bound(a.begin(),a.end(),2*p)-a.begin();
        int ps=a[sp-1];

        if(prev==ps)break; 
        p=ps;
        ans=min(ans,sum-p);

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