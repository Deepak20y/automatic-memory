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
 vector<int>b;
bool ok;
int root;
 int dfs(int s,int parent=-1)
 {
     int st=0;
    
     for(auto &x:adj[s])
     {
        if(x==parent)continue;
         st+=dfs(x,s);
     }

     if(binary_search(b.begin(),b.end(),s))
     {      st++;
            if(root==s&&st>3)ok=false;
            else if(root!=s&&st>=3)ok=false;
     }
     else{
          
          if(st>1)ok=false;

     }

     st=min(st,1);
     

     return st;
     

 }

 void solve(){
        int n;cin>>n;
       adj.resize(n);

       for(int i=1;i<n;i++)
       {  
         int p,q;cin>>p>>q;
         adj[--p].push_back(--q);
         adj[q].push_back(p);

       }

       int q;cin>>q;
       while(q--)
       {  int p;cin>>p;
          ok=true;
         for(int i=0;i<p;i++)
         {
             int m;cin>>m;
             b.push_back(--m);
         }

         
          sort(b.begin(),b.end());
         // for(auto &x:b)cout<<x<<" ";cout<<endl;
          root=b[0];
          dfs(b[0]);
         
         if(ok)cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
            b.clear();

       }





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}