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
       int q;cin>>q;
       set<int>a;
   
    vector<int>ans(n+1,0);
      
  for(int i=1;i<=n;i++)a.insert(i);
      while(q--)
      {
         int l,r;cin>>l>>r;
         int x;cin>>x;
          queue<int>pq;
         auto sp=a.lower_bound(l);
        // cout<<*sp<<endl;
         while(sp!=a.end()&&*sp<=r)
         {  //cout<<x<<" "<<*sp<<endl;
            if(*sp==x)r=r;
            else{
              ans[*sp]=x;
              pq.push(*sp);
            }
            sp++;
         }

         while(!pq.empty())
         {
            a.erase(pq.front());
            pq.pop();
         }

      }


      for(int i=1;i<=n;i++)cout<<ans[i]<<" ";






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}