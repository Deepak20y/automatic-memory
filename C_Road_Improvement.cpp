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
vector<vector<int>>adj;
 vector<vector<int>>days;
 void solve(){
       int n;
       cin>>n;
    
    adj.resize(n+1);
    map<int,map<int,int>>b;

     for(int i=1;i<n;i++)
     {  
        int l,r;cin>>l>>r;

         b[l][r]=i;
         b[r][l]=i;
         adj[l].push_back(r);
         adj[r].push_back(l);

     }

      vector<int>day(n+1,-1);
      vector<int>vis(n+1,false);
      day[1]=0;
      queue<int>q;
      q.push(1);
     days.resize(n+4);
      int maxp=0;

      while(!q.empty())
      {
          int p=q.front();
          q.pop();
         int cnt=1;
          vis[p]=true;
          for(auto &x:adj[p])
          {  if(vis[x])continue;
             if(cnt==day[p])cnt++;
              day[x]=cnt;
             // cout<<p<<" "<<x<<" "<<b[p][x]<<endl;;
              days[cnt].push_back(b[p][x]);
              q.push(x);
              maxp=max(cnt,maxp);
              cnt++; 
          }

      }
        // for(auto &x:vis)cout<<x<<" ";cout<<endl;
        cout<<maxp<<endl;
      for(int i=1;i<=n;i++)
      {
         if(days[i].size()==0)break;
         cout<<days[i].size()<<" ";
         for(auto &x:days[i])cout<<x<<" ";cout<<endl;
      }





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}