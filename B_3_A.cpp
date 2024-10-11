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
       int n;
       cin>>n;

       vector<int>a;

       while(n>0)
       {
           a.push_back(n%3);
           n/=3;
       }

       

       vector<int>ans;
         int p=0;
       for(int i=0;i<a.size();i++)
       {
          while(a[i]--)ans.push_back(p);
          p++;
       }
    
    cout<<ans.size()<<endl;
   for(auto &x:ans)cout<<x<<" ";cout<<endl;

     




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
solve();
return 0;
}