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
  vector<int>dp(n+5,0);


  for(int i=0;i<n;i++)
  {  
        if(a[i]>k){dp[i]++;continue;}

     for(int j=i;j<n;j++)
     {    
          ll sp=a[j];
           if(j-1>=0)sp-=a[j-1];

          auto up=upper_bound(a.begin()+j,a.end(),k+sp-1);

          if(up==a.end());
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