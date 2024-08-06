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
       ll n,k;
       cin>>n>>k;

  vector<ll>a(n);

  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n-1;i++)a[i+1]+=a[i];

  for(int i=0;i<n;i++)
  {
     if(a[i]>k)
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