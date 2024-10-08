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
       vector<ll>a(n);
       for(int i=0;i<n;i++)cin>>a[i];

       sort(a.begin(),a.end());

      for(int i=0;i<n-1;i++)
      { 
        a[i+1]+=a[i];
         
      }

      ll p=0;

      for(int i=1;i<n;i++)
      {
            p+= (a[i]-a[i-1])*i-a[i-1];
      }
      p*=2LL;
      p+=a[n-1];

      cout<<p/gcd(p,n)<<" "<<n/gcd(p,n)<<endl;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}