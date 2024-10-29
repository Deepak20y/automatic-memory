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
     int n=3;
       vector<int>a(n);
       for(int i=0;i<3;i++)cin>>a[i];
       sort(a.begin(),a.end());

       if(a[0]+a[1]==a[2])cout<<"YES"<<endl;
       else cout<<"NO"<<endl;





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