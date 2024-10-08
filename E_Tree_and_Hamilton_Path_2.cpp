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
 vector<pair<int,int>>adj[200005];
vector<bool>vis;
vector<ll>dist;

 void dfs(int p)
 { 
    vis[p]=true;
    for(auto &[x,y]:adj[p])
    {
        if(vis[x])continue;
        dist[x]+=dist[p]+(ll)y;
        dfs(x);
    }


 }
 void solve(){
        ll ans=0LL;
   int n;cin>>n;
   for(int i=0;i<n-1;i++)
   { int a ,b,r;
      a,b,r;cin>>a>>b>>r;

       a--;
       b--;
       adj[a].push_back({b,r});
       adj[b].push_back({a,r});
       ans+=r;
       ans+=r;
   }



      dist.assign(n,0);
 vis.assign(n,false);

  dfs(0);
    
ll maxp=0LL;
int root=0;
for(int i=0;i<n;i++)
{
    if(maxp<dist[i]){maxp=dist[i];root=i;}
} 


///cout<<root<<endl;

 vis.assign(n,false);
 dist.assign(n,0);
  dfs(root);
 maxp=0;

  for(int i=0;i<n;i++)
  {
     maxp=max(dist[i],maxp);
  }
//for(auto &x:dist)cout<<x<<" ";cout<<endl;
  cout<<ans-maxp<<endl;


    



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}