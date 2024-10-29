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

       for(int i=0;i<n;i++)cin>>a[i];


            sort(a.begin(),a.end());


       cout<<a[n-1]<<" ";

       for(int j=1;j<n-1;j++)cout<<a[j]<<" ";

       cout<<a[0]<<endl;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}