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
 
  bool dp[505][505][505]={false};

// dp[i][j][k] dennotes if we take the i th element to form subset j and from that subset make k
// ican optimize the space here as only two arrays are need make the position better
 void solve(){
       
 int n;cin>>n;
 int ks;cin>>ks;
 vector<int>a(n);
 for(int i=0;i<n;i++)cin>>a[i];
  dp[0][0][0]=true;
     
     for(int i=1;i<=n;i++)
     {
        dp[i][0][0]=true;
     }

     for(int i=1;i<=n;i++)
     {
       for(int j=0;j<=ks;j++)
       { 
         for(int k=0;k<=j;k++)
         {

           dp[i][j][k]|=dp[i-1][j][k];
           if(j>=a[i-1])dp[i][j][k]|=dp[i-1][j-a[i-1]][k];
           if(k>=a[i-1])dp[i][j][k]|=dp[i-1][j-a[i-1]][k-a[i-1]];
         //  cout<<i<<" "<<j<<" "<<k<<endl;
         }
         

       }

     }
     set<int>ans;

    
        
           for(int i=0;i<=ks;i++)
           {
                if(dp[n][ks][i])ans.insert(i);
           }
        
        
     

     cout<<ans.size()<<endl;

     for(auto &x:ans)cout<<x<<" ";







return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}