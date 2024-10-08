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

// dp1 is the number of ways in which first person and nth person number is same
//  dp2 is the numeber of ways in which last person and first person numbers are not same
// a(n+1)=b(n) means i can assign first person integer to (n+1)th person  as
// first person and nth person number are not same
// b(n + 1) = b(n) * (M — 2) + a(n) * (M — 1) 
//you have to avoid both person 1's number and person n's number, leaving M — 2 options,
// unless those are the same, in which case you have M — 1 options. 

const int mod=998244353;
 void solve(){
       ll n,m;
       cin>>n>>m;
       vector<ll>dp1(n+5,0LL),dp2(n+5,0LL);

       dp1[1]=m; // base case
       dp2[1]=0; //base case

      for(int i=1;i<n;i++)
      {   
         dp1[i+1]=dp2[i];
         dp2[i+1]=dp2[i]*(m-2LL)+dp1[i]*(m-1LL);
         
         dp1[i+1]%=mod;
         dp2[i+1]%=mod;
          
      }

      cout<<dp2[n];






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}