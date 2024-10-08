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
       
       vector<int>a(105,0);
   

    int l,r;cin>>l>>r;

    for(int i=l;i<=r;i++)a[i]++;
    cin>>l>>r;
    for(int i=l;i<=r;i++)a[i]++;
    
 int cnt=0;

  for(int i=1;i<=100;i++)
  {
   if((a[i]==1&&a[i+1]==2)||(a[i]==2&&a[i+1]==1)||(a[i]==2&&a[i+1]==2))cnt++;
  }

   cout<<max(1,cnt)<<endl;


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