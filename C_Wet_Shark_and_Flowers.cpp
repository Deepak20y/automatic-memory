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
       
       int n,p;cin>>n>>p;

       ll ans=0LL;

       vector<pair<int,int>>a;

       for(int i=0;i<n;i++)
       {
            int l,r;cin>>l>>r;

            int sp=l-1;
            int mp=r/p-sp/p;

            a.push_back({mp,r-l+1-mp}); //divisor,non divisor

       }


       for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;







return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}