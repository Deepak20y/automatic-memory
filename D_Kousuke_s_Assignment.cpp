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
       map<ll,ll>a;

       int ans=0;
       a[0]=1;
       ll sum=0LL;
       for(int i=0;i<n;i++)
       {  
        int m;cin>>m;
        sum+=m;

         if(a.find(sum)!=a.end())
         {ans++;a.clear();a[0]=1;sum=0;}
         else a[sum]++;

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