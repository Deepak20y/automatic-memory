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

       int x=0;
     int cnt=0;
      int i=1;
       while(abs(x)<=n)
       {
          if(cnt==0)
          {
             x-=2*i-1;
          }
          else
          {
             x+=2*i-1;
          }

          i++;
         // cout<<cnt<<" "<<x<<endl;
          cnt=1-cnt;

          
       }

       if(cnt==0)cout<<"Kosuke"<<endl;
       else cout<<"Sakurako"<<endl;





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