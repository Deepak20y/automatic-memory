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
   int cnt;
   int component;
   vector<int>sd;
   int n,m;
vector<vector<char>>a;
 vector<vector<int>>b;
 void dfs(int i,int j)
 {
      b[i][j]=component;
       cnt++;
      if(i-1>=1&&b[i-1][j]==0&&a[i-1][j]=='#')dfs(i-1,j);
      if(j-1>=1&&b[i][j-1]==0&&a[i][j-1]=='#')dfs(i,j-1);
      if(i+1<=n&&b[i+1][j]==0&&a[i+1][j]=='#')dfs(i+1,j);
      if(j+1<=m&&b[i][j+1]==0&&a[i][j+1]=='#')dfs(i,j+1);

 }

 void solve(){
       cin>>n;
       cin>>m;
       
       a.assign(n+5,vector<char>(m+5,'.')); 
       b.assign(n+5,vector<int>(m+5,0));


       for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)cin>>a[i][j];
       

        cnt=0;
        component=1;
        sd.push_back(0);


       for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
            if(b[i][j]>0||a[i][j]=='.')continue;
             cnt=0;
             dfs(i,j);
             sd.push_back(cnt);
             component++;

            
            
       }
      //for(auto &x:sd)cout<<x<<" ";cout<<endl;

      int ans=0;

      for(int i=1;i<=n;i++)
      {
         map<int,int>d;
         int ps=0;
         for(int j=1;j<=m;j++)
         { 
            if(a[i][j]=='.')ps++;
            if(d.find(b[i-1][j])==d.end())
            {
              ps+=sd[b[i-1][j]];
              d[b[i-1][j]]++;

            }

             if(d.find(b[i][j])==d.end())
            {
              ps+=sd[b[i][j]];
              d[b[i][j]]++;
            }

           if(d.find(b[i+1][j])==d.end())
            {
                  ps+=sd[b[i+1][j]];
              d[b[i+1][j]]++;

            }
            



         }
          ans=max(ans,ps); 
          d.clear();

      }

      for(int j=1;j<=m;j++)
      {
         map<int,int>d;
         int ps=0;
         for(int i=1;i<=n;i++)
         { 
            if(a[i][j]=='.')ps++;
            if(d.find(b[i][j-1])==d.end())
            {
              ps+=sd[b[i][j-1]];
              d[b[i][j-1]]++;

            }

             if(d.find(b[i][j])==d.end())
            {
              ps+=sd[b[i][j]];
              d[b[i][j]]++;
            }

           if(d.find(b[i][j+1])==d.end())
            {
                  ps+=sd[b[i][j+1]];
              d[b[i][j+1]]++;

            }
            



         }
          ans=max(ans,ps); 
          d.clear();

      }
        
        cout<<ans<<endl;



 a.clear();b.clear();sd.clear();




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