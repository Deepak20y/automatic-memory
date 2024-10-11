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
 vector<ll>temp;
ll tem=0LL;
vector<bool>take;
vector<int>ans;
   int start;
 void dfs(int s,int parent=-1)
 {    
     //cout<<s<<" "<<parent<<endl;
      
     for(auto &x:adj[s])
     {
         if(x!=parent)
        { dfs(x,s);
             temp[s]+=temp[x];
         take[s]=take[x]|take[s];
        }
    
      
        
     }
     
   //  cout<<s<<" "<<tem<<" "<<temp[s]<<endl;
               if(start!=s)
         {if(take[s]&&2*tem==temp[s]){ans.push_back(s);take[s]=true;}
         if(take[s]==false&&tem==temp[s]){ans.push_back(s);take[s]=true;}}
         

     

     return;
      
 }


 void solve(){
     int n;
     cin>>n;

     adj.resize(n+3);
     temp.resize(n+3,0);
     take.resize(n+3,false);

  
     
     for(int i=1;i<=n;i++)
     {  

        int l,t;cin>>l>>t;

        if(l==0)start=i;
        temp[i]=t;
        tem+=t;
        if(l>0)
        {adj[l].push_back(i);
        adj[i].push_back(l);}

     }   
      if(tem%3!=0){cout<<-1<<endl;return;}
      tem/=3;
   
         take[start]=true;
       dfs(start);
       //cout<<tem<<endl;

      //  for(auto x:take)cout<<x<<" ";cout<<endl;
      //   cout<<ans.su
       if(ans.size()<2)cout<<-1<<endl;
       else cout<<ans[0]<<" "<<ans[1]<<endl;

      
       

   




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}