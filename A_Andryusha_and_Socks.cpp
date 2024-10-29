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
       int maxp=0;
          set<int>a;
          int n;cin>>n;
       for(int i=0;i<2*n;i++)
       {   
         int m;cin>>m;

         if(a.find(m)==a.end())a.insert(m);
         else a.erase(m);
         maxp=max((int)a.size(),maxp);
    
       }

       cout<<maxp<<endl;





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}