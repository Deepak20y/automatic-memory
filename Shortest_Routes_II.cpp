#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
/*I liked you once but not anymore now*/
vector<pair<ll,ll>>adj[505];

ll dp[505][505];
void pt(int n,int sp)
{
    vector<bool>vis(n+5,false);
      vector<ll>dist(n+5,1e16);
    priority_queue<pair<ll,ll>>q;
   q.push({0,sp});
   dist[sp]=0;
   while(!q.empty())
   {
      int p=q.top().second;
      q.pop();
      if(vis[p])continue;
      vis[p]=true;
 
      for(auto &[x,w]:adj[p])
      {
        if(vis[x])continue;
         if(dist[p]+(ll)w<dist[x])
         {
            dist[x]=dist[p]+(ll)w;
           
         }
         q.push({-dist[x],x});
      }
 
   }
 
   for(int i=1;i<=n;i++)dp[sp][i]=dist[i];
 
}


 void solve(){
       int n;cin>>n;
          int m;cin>>m;
    
  int q;cin>>q;
      for(int i=0;i<m;i++)
      {
         int p,qt,w;cin>>p>>qt>>w;
         adj[p].push_back({qt,w});
           adj[qt].push_back({p,w});
       //  adj[q].push_back({p,w});
      }
      
      for(int i=1;i<=n;i++)pt(n,i);

      while(q--)
      {
         int a,b;cin>>a>>b;
         if(dp[a][b]==1e16)cout<<-1<<endl;
         else cout<<dp[a][b]<<endl;
      }

 
 
return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
 
solve();
return 0;
}