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
       ll n;cin>>n;ll k;cin>>k;
       ll arr[n];
       ll maxi = 0;
       for(int i=0;i<n;i++)cin>>arr[i] , maxi = max( maxi , arr[i]);
       ll left = maxi , right = maxi + k - 1;

       for(int i=0;i<n;i++){
          // ai + x*k = l
          // x = l - ai /k
          int p = (left  - arr[i] ) / k;
          if(p&1){
             p++;
          }
          ll aleft = arr[i] + k*p;
          ll aright = aleft + k - 1;
          left = max(left , aleft);
          right = min(right , aright);

       }
       if(left > right){
        cout<<-1<<endl;
       }else{
        cout<<left<<endl;
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