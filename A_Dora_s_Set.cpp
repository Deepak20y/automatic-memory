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
       int l,r;
       cin>>l>>r;
       
       int odd=0;
       int even=0;
       for(int i=l;i<=r;i++)
       {
          if(i%2==0)even++;
          else odd++;
       }

      int ans=0;

    while(odd>=2&&even>=1)
    {
         odd-=2;
         even--;
         ans++;
    }

  while(odd>=3){ans++;odd-=3;}
 
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