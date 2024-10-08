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

 void solve(){
       int n;cin>>n;

    set<int>a[n+2];
    set<int>sq,q;
    vector<bool>vis(n+4,false);
    vector<int>degree(n+4,0);
    for(int i=1;i<=n;i++)
    { 
        int m;cin>>m;
        if(m!=0)
        for(int j=0;j<m;j++)
        {
               int p;cin>>p;
             
             a[p].insert(i);
             degree[i]++;
        }
        else {q.insert(i);vis[i]=true;}
        
    }

    if(q.size()==0){cout<<-1<<endl;return;}
 int reading =1;
  while(reading<n+2&&!q.empty())
  {
        
        int mp=*q.begin();
        q.erase(q.begin());

        for(auto &x:a[mp])
        {  
            degree[x]--;
            if(degree[x]==0&&x>mp){q.insert(x);vis[x]=true;}
            else if(degree[x]==0&&x<mp){sq.insert(x);vis[x]=true;}

        }
       
       if(q.size()==0&&sq.size()>0)
       {
         for(auto &x:sq)q.insert(x);
         reading ++;
         sq.clear();
       }

  }
  int totalread=0;
  for(int i=1;i<=n;i++)if(vis[i])totalread++;
  if(totalread<n){cout<<-1<<endl;return;}

  cout<<reading<<endl;




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