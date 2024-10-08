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

    bool ok=true;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
     bool ok2=false;
    for(int i=0;i<n-1;i++)if(a[i+1]<a[i])ok=false;

    if(ok){cout<<0<<endl;return;}


   set<int>b;
   for(int i=0;i<n-1;i++)
   {
      b.insert(a[i]);
      auto sp=b.end();
      sp--;
 //cout<<b.size()<<" "<<*sp<<" "<<a[i]<<endl;
     if(*sp==b.size()&&*sp==a[i]){cout<<1<<endl;return;}
   }


 cout<<2<<endl;

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