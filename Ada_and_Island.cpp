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
   
 int n,m;
int cnt;

 void dfs(int i,int j,vector<vector<char>>&a,vector<vector<bool>>&vis)
 {
    vis[i][j]=true;
    cnt++;
    if(i+1<=n&&vis[i+1][j]=='#'&&!vis[i+1][j])dfs(i+1,j,a,vis);
     if(j+1<=m&&vis[i][j+1]=='#'&&!vis[i][j+1])dfs(i,j+1,a,vis);
      if(i-1>=1&&vis[i-1][j]=='#'&&!vis[i-1][j])dfs(i-1,j,a,vis);
       if(j-1>=1&&vis[i][j-1]=='#'&&!vis[i][j-1])dfs(i,j-1,a,vis);

 }
  

 void solve(){
        
 cin>>n>>m;
 vector<vector<char>>a(n+2,vector<char>(m+3));
 vector<vector<bool>>vis(n+2,vector<bool>(m+3));


   for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)cin>>a[i][j];

map<int,int>b;

   for(int i=1;i<=n;i++)
   { 
     for(int j=1;j<=m;j++)
     {     cnt=0;
         if(!vis[i][j]&&a[i][j]=='#'){dfs(i,j,a,vis);b[cnt]++;}
     }

   }

 ll ans=0;

 for(auto &[x,y]:b)
 { cout<<x<<" "<<y<<endl;
    ans+=x*x*y;
 }
    ll p=m*n;
   cout<<ans<<" "<<p<<endl;
    ll s=gcd(p,ans);
    ans/=s;
    p/=s;

    if(ans==0)cout<<0<<endl;
    else if(p==1)cout<<ans<<endl;
    else cout<<ans<<" / "<<p<<endl;






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
while(t--)
solve();
return 0;
}