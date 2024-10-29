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
  vector<long long>fact;
  const int mod=1e9+7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 void solve(){
       int t;cin>>t;
       vector<long long>a(t);
       vector<long long>b(t);

       for(int i=0;i<t;i++)cin>>a[i];
     for(int i=0;i<t;i++)cin>>b[i];
     fact.push_back(1);
     for(long long i=1;i<=1e5+5;i++)
     {
        fact.push_back((fact.back()*i)%mod);
     }

  


     for(int i=0;i<t;i++)
     {  
     
        long long x=a[i];
        long long y=b[i];
        
     
     cout<<binpow(2LL,y,mod)<<endl;



     }





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}