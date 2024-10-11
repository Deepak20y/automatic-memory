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
   int maxp=0;
   int maxp1=0;

     for(int i=0;i<n;i++)
     {
        int m;cin>>m;
        
        if(i%2==0)maxp=max(maxp,m);
        else maxp1=max(maxp1,m);

     }


    cout<<max(n/2+n%2+maxp,n/2+maxp1)<<endl;

       







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