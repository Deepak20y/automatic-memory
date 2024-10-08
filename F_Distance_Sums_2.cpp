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

//very thoughtful question
// i have decided to do dfs for first and then
//read the editorial for more better understanding 
//you have already understood the problem very well as well the solution
 vector<int>adj[200005];
 void solve(){
        int n;
        cin>>n;

       for(int i=1;i<n;i++)
       {
         int a,b;cin>>a>>b;
         a--;
         b--;

         adj[a].push_back(b);
         adj[b].push_back(a);
       }
        
    vector<ll>subtree(n,1);
    vector<ll>ans(n,0LL);

    function<void(int,int,int)>dfs=[&](int sp,int p,int d)
    {
         ans[0]+=d;

         for(auto &x:adj[sp])
         if(x!=p){
             
             dfs(x,sp,d+1);
             subtree[sp]+=subtree[x];
         }
    };
    dfs(0,-1,0);


 function<void(int, int)> dfs2=[&](int i, int p){
        for(int x : adj[i]) if(x != p) {
            ans[x] = ans[i] - 2 * subtree[x] + n;
            dfs2(x, i);
        }
    }; dfs2(0, -1);
  

 for(auto &x:ans)cout<<x<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}