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
       int x,y;cin>>x>>y;
       int n;cin>>n;

 int ans=0;

   for(int i=0;i<n;i++)
   {
       
       ans+=max(2*x+2*y-4,0);
        

     x-=4;y-=4;
   }
    cout<<ans<<endl;


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}