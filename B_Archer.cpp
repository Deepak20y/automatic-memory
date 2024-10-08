#include<bits/stdc++.h>
using namespace std;
using ll =long double;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

 void solve(){
       


 ll a,b,c,d;
 cin>>a>>b>>c>>d;


   cout<<setprecision(15)<<(a*d)/((b*d)-(b-a)*(d-c))<<endl;


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}