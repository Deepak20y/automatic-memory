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
  ll lower[1000005],upper[1000005];
 void sol()
 {  
    lower[0]=0;
    upper[0]=0;

 lower[1]=1;
 upper[1]=0;

  for(int i=2;i<=1e6;i++)
  {
        lower[i]=3*lower[i-1]+upper[i-1]+(lower[i-1]/4)*4;
        upper[i]=3*upper[i-1]+lower[i-1]+(upper[i-1]/4)*4;

  }
    
    
     
 }
 void solve(){
       
       

 int n;cin>>n;
 cout<<lower[n]+upper[n]<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
sol();
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}