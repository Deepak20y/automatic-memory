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

//its alternative is star bar theorem meaning using permutaion to find the answer
//but i wanted to find the dp solution
const int mod=1e9+7;
 void solve(){
        int n;cin>>n;
        int m;cin>>m;
         
         
         vector<vector<ll>>dp(2*m+5,vector<ll>(n+5,0));

          
          for(int i=1;i<=n;i++)dp[1][i]=1;


          for(int i=2;i<=2*m;i++)
          {  
             ll sum=0LL;
            for(int j=1;j<=n;j++)
            {   
                 sum+=dp[i-1][j];
                
                dp[i][j]+=sum;
                sum%=mod;
                dp[i][j]%=mod;

            }
           
          }


        ll ans=0LL;

        for(int i=1;i<=n;i++){ans+=dp[2*m][i];ans%=mod;}


  cout<<ans;








return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}