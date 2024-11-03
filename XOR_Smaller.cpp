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
       
       vector<int>a(30,0);
       int n;cin>>n;

    
     for(int i=0;i<n;i++)
     {
        int m;cin>>m;

        for(int j=0;j<30;j++)
        {
            if((1<<j)&m)a[j]++;
        }
     }
 ll ans=0LL;
 for(int j=30;j>=0;j--)
 {
    if(a[j]==n)
    {
        ans+=pow(2LL,j);
    }
 }

 cout<<ans<<endl;
     

// cout<<0<<endl;
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