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
       vector<int>a(n);
      vector<ll>t1(n+2,0),t2(n+2,0);
       for(int i=0;i<n;i++){cin>>a[i];t2[a[i]]++;}
 
 ll ans=0LL;
       for(int i=0;i<n;i++)
       {
         t2[a[i]]--;
         vector<ll>t3(n+2);
         t3=t2;

        for(int j=i+1;j<n;j++)
        {
           t3[a[j]]--;
           ans+=t3[a[i]]*t1[a[j]];

        }
         
         t1[a[i]]++;
       }

       cout<<ans<<"\n";





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