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
  
       string s;cin>>s;
       string t;cin>>t;
     int n;cin>>n;
       cout<<s<<" "<<t<<endl;

       for(int i=0;i<n;i++)
       {
          string p,q;cin>>p>>q;

          if(s==p)
          {
            s=q;
          }
          else t=q;

          cout<<s<<" "<<t<<endl;


       }







return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}