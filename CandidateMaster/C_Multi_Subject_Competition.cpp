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
vector<int>adj[100005];
 void solve(){
       int n;cin>>n;
       int m;cin>>m;
       
       
       
       for(int i=0;i<n;i++)
       {
            int a,b;cin>>a>>b;
            a--;
            adj[a].push_back(b);
       }

       for(int i=0;i<m;i++) if(adj[i].size()>0)sort(adj[i].begin(),adj[i].end(),greater<int>());
      
      set<int>b;
     

      for(int i=0;i<m;i++)
      {   
         if(adj[i].size()>0)
         {for(int j=0;j<adj[i].size()-1;j++)adj[i][j+1]+=adj[i][j];
         b.insert(i); }
      }

      
   ll ans=0LL;
     int cnt=1;
     while(!b.empty())
     {
        
        queue<int>q;
       ll sum=0LL;
       for(auto &x:b)
       {
          if(adj[x][cnt-1]>0)sum+=adj[x][cnt-1];
          if(adj[x].size()==cnt)q.push(x);
       }
          ans=max(ans,sum);
          while(!q.empty())
          {
            b.erase(q.front());
            q.pop();
          }

          cnt++;

     }

     cout<<ans<<endl;


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}