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
       if(n%2==0)cout<<-1<<endl;
       else{

         for(int i=1;i<=n/2;i++)cout<<i<<" ";
         for(int i=n;i>n/2;i--)cout<<i<<" ";
         cout<<endl;
       }



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