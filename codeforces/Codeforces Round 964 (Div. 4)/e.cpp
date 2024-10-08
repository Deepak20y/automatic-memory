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
 vector<int>dp;
 void fill()
 {   int m;
     m=2e5;
     dp.assign(m+5,0);
    for(int i=1;i<=m;i++)
    {
         int p=i;
          int cnt=0;
          while(p>0){cnt++;p/=3;}
          dp[i]=cnt;
    }

    for(int i=0;i<=m;i++)
    {
        dp[i+1]+=dp[i];
    }

 }


 void solve(){
       
 int l,r;cin>>l>>r;
  
  cout<<dp[r]-dp[l-1]+dp[l]-dp[l-1]<<endl;





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
fill();

int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}