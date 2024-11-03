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
       
       map<ll,ll>a;
     int n;cin>>n;
     int k;cin>>k;
       for(int i=0;i<k;i++)
       { 
          int p;cin>>p;
          int q;cin>>q;
          a[p]+=q;

       }

       vector<ll>ans;

       for(auto &[x,y]:a)
       {
        ans.push_back(y);
        //cout<<x<<" "<<y<<endl;
       }

       sort(ans.begin(),ans.end(),greater<ll>());


      int i=0;
      ll fin=0;
      while(i<ans.size()&&n--)
      {
          fin+=ans[i];
          i++;
      }

      cout<<fin<<endl;







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