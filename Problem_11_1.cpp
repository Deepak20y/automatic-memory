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
      int target;
      cin>>target;
      int idx=0;
      for(int i=0;i<n;i++)
      {
        if(a[i]<target)idx=i+1;
        else if(a[i]==target){idx=i;break;}
      }
  cout<<idx<<endl;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}