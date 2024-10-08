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
       ll n;cin>>n;



       vector<pair<int,int>>a(n);
        map<int,ll>b,c;
        ll ans=(n*(n-1)*(n-2))/6LL;
        for(int i=0;i<n;i++)
        {  
            
           int x,y;cin>>x>>y;
           a[i].first=x;
           a[i].second=y;
           b[x]++;
           c[y]++;
        }

       
       for(int i=0;i<n;i++){
         
         ans-=(b[a[i].first]-1)*(c[a[i].second]-1);
         
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