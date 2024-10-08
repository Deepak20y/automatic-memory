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
 bool dp[1005][1005]={false};
 void solve(){
       int n;cin>>n;
       int k;cin>>k;


        int a,b,c,d;
        cin>>a>>b>>c>>d;
    
    dp[a][b]=true;
    dp[b][a]=true;
    dp[c][d]=true;
    dp[d][c]=true;
     
     vector<int>ans(n+2,0);

    ans[0]=a;
    ans[1]=c;
    ans[n-1]=d;
    ans[n-2]=b;


    
     

        





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