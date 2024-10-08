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
 ll dp[3003][3003];

 void solve(){
       

 int n;cin>>n;
 vector<int>a(n);
 for(int i=0;i<n;i++)cin>>a[i];
 

 for(int i=n-1;i>=0;i--)
 for(int j=i;j<n;j++)
 {
    if(i==j)dp[i][j]=a[i];
    else dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);

 }

 cout<<dp[0][n-1]<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}