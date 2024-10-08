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


      if(n==1){cout<<a[0]<<endl;return;}

      int i=0;
      int j=n-1;
      bool ok=true;
      while(j-i>1)
      { 
        if(ok)i++;
        else j--;
         ok=!ok;
         
      }
      
    //   for(auto &x:a)cout<<x<<" ";cout<<endl;
    //   cout<<i<<" "<<j<<endl;
     if(n%2==0)cout<<max(a[i],a[j])<<endl;
     else cout<<min(a[i],a[j])<<endl;




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