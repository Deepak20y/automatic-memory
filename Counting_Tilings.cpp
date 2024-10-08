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
 
 const int mod=1e9+7;
 ll dp[13];
 void solve(){
       int n,m;cin>>n>>m;
       dp[1]=1;
       dp[2]=2;

       for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
            
     for(int i=)






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