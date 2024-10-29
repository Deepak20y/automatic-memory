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
       int p=0;

       for(int i=0;i<n;i++){cin>>a[i];p=gcd(p,a[i]);}


       sort(a.begin(),a.end());


   int m=(a[n-1]-p)/p+1;

   m-=n;

    

    if(m%2==0)cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}