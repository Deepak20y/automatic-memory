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
 vector<int>adj[200005];
 void solve(){
       int n;cin>>n;
       
    int m;cin>>m;m--;
    for(int i=1;i<n;i++)
    {
         int a,b;cin>>a>>b;
         a--;b--;
         adj[a].push_back(b);
         adj[b].push_back(a);
    }
  
  vector<int>dist(n,0);
  vector<int>vis(n,false);
   queue<int>q;
   q.push(0);
   while(!q.empty())
   {
       int p=q.front();
       q.pop();
      if(vis[p])continue;
     vis[p]=true;
   //  cout<<p<<" ";
     for(auto &x:adj[p])
     {      if(vis[x])continue;
           dist[x]=1+dist[p];
           q.push(x); 
     }

   } 


  // for(auto &x:dist)cout<<x<<" ";cout<<endl;



  vector<int>dist2(n,0);
  vis.assign(n,false);
  q.push(m);
 while(!q.empty())
   {
       int p=q.front();
       
       q.pop();
      if(vis[p])continue;
     vis[p]=true;
    // cout<<p<<" ";
     for(auto &x:adj[p])
     {     
           if(vis[x])continue;
           dist2[x]=1+dist2[p];

       
           q.push(x); 
     }

   } 
   //cout<<dist2[m]<<endl;
  //   cout<<endl;
  //  for(auto &x:dist)cout<<x<<" ";cout<<endl;
  //  for(auto &x:dist2)cout<<x<<" ";cout<<endl;
      int ans=0;

   for(int i=1;i<n;i++)
   {
     if(dist[i]>dist2[i])ans=max(ans,2*dist[i]);
   }

   cout<<ans;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}