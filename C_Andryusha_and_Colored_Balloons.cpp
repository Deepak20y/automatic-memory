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
vector<vector<int>>a;

vector<int>color,parent_color;
vector<bool>vis;
 void solve(){
       int n;cin>>n;
       a.resize(n);
       color.resize(n);
       parent_color.resize(n);
       vis.assign(n,false);
       for(int i=1;i<n;i++)
     {
          int p,q;cin>>p>>q;
          a[--p].push_back(--q);
          a[q].push_back(p);

     }

    

    queue<int>q;
    q.push(0);
    int maxp=1;
    color[0]=1;
    parent_color[0]=0;
    while(!q.empty())
    {

        int p=q.front();
        q.pop();
        vis[p]=true;
      
         int cnt=1;
        for(auto &x:a[p])
        {
            if(vis[x])continue;
            
            while(cnt==parent_color[p]||cnt==color[p])cnt++;
             while(cnt==parent_color[p]||cnt==color[p])cnt++;
          
             color[x]=cnt;
             parent_color[x]=color[p]; 
            maxp=max(cnt,maxp);
             cnt++;
             q.push(x);
             
        }

    }
    cout<<maxp<<endl;
    for(auto &x:color)cout<<x<<" ";

    

       
       





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}