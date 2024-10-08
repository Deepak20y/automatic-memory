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

long long int dp[1000005][2];
const int mod=1e9+7;
 void solve(){
       int n;cin>>n;

       dp[1][0]=1;// ways of placing tile of size of 1 on ith position
       dp[1][1]=1;//ways of palcing tile of size 2 in ith position

       for(int i=2;i<=n;i++)
       {
         dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%mod;
         dp[i][0]=(dp[i-1][1]+4*dp[i-1][0])%mod;

       }

       cout<<(dp[n][0]+dp[n][1])%mod<<endl;


       





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