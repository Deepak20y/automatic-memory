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
        map<int,int>a;
          int sp=0;
        for(auto &[x,y]:a)
        { 
            if(y%2==1&&x!=0)sp=1;

        }
         
         if(sp==1)cout<<"YES"<<endl;
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