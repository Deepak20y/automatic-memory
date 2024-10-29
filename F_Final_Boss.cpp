#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using ll =long long int;
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
bool cmp(const pair<ll,ll>&aa,const pair<ll,ll>&bb)
{
    if(aa.first==bb.first)return aa.second<bb.second;
    else return aa.first<bb.first;
}
void solve()
{


    set<pair<ll,ll>,bool(*)(const pair<ll,ll>&,const pair<ll,ll>&)>c(cmp);
 ll h,n;cin>>h>>n;
vector<int>a(n),b(n);
 for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  
   for(int i=0;i<n;i++)
   {
    c.insert({0,i});
   }

ll i=0LL;

while(true)
{   i=max(i,(ll)c.begin()->first);
     while(true)
     {
         pair<ll,ll>d=*c.begin();
         if(d.first>i)break;
        c.erase(c.begin());
         d.first+=b[d.second];
          h-=a[d.second];
          c.insert(d);
     }


    if(h<=0){cout<<i+1<<endl;return;}
   //if(i>1e7)break;

}

return;
}
int main()
{
int t; 
cin>>t;
while(t--)
 solve();
return 0;
}