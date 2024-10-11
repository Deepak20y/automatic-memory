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


 if(n==1)cout<<2<<endl;
 else if(n==2)cout<<3<<endl;
 else  if(n==3||n==4)cout<<4<<endl;
 else 
 {
       int p=sqrt(n);
       n-=p;
       int m=p+1+(n/p)+bool(n%p);

       cout<<m<<endl;


 }



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}