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
vector<ll>a;
vector<ll>b;
int n;
ll k;
ll ans;
bool sea(ll mid,ll sum)
{
   auto sp=lower

}
 void solve(){
      ans=1e17;
        cin>>n>>k;
        a.resize(n);
        b.resize(n);
        for(int i=0;i<n;i++)
        { 
            cin>>a[i];
          
        }
        sort(a.begin(),a.end());
 
 ll sum=0LL;
 for(int i=0;i<n;i++)
 { 
     b[i]=a[i];sum+=a[i];
 }
  
  for(int i=0;i<n-1;i++)a[i+1]+=a[i];



  ll low=a[0];
  ll mid;
  ll high=a[n-1];
 
  for(int i=0;i<70;i++)
  {
      mid=(high+low)/2LL;
      if(sea(mid,sum))high=mid;
      else low=mid;
  }




cout<<ans<<endl;

return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}