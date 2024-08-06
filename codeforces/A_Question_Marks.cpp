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
  string s;cin>>s;

   vector<int>a(4);
 int cnt=0;
  for(int i=0;i<4*n;i++)
  {
       if(s[i]=='?')cnt++;
       else a[s[i]-'A']++;
  }
  //for(auto &x:a)cout<<x<<" ";cout<<endl;
  int ans=0;
  for(int i=0;i<4;i++)
  {
      if(a[i]>=n)ans+=n;
      else ans+=a[i];

  }
  cout<<ans<<endl;


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