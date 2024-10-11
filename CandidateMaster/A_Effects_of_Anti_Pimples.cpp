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
 
 const int mod= 998244353;

 long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

vector<ll>fact;


long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

 void solve(){
       int n;cin>>n;
       map<int,int>d;

       vector<ll>a(n);

       for(int i=0;i<n;i++){cin>>a[i];d[a[i]];}


       sort(a.begin(),a.end());
       
   set<int>b;
    ll ans=0LL;

//for(auto &x:a)cout<<x<<" ";cout<<endl;
    
  for(int i=n-1;i>=0;i--)
  {     
       if(b.find(a[i])!=b.end())continue;
       
        ll cnt=1;
        //cout<<i<<endl;
       while(i-1>=0&&a[i]==a[i-1]){i--;cnt++;}
 
            int divisor=0;

            set<int>c;
            int p=i;
     for(int j=2;j*j<=a[i];j++)
     {
         if(a[i]%j==0)
         {
                if(d.find(a[i]/j)!=d.end()) // number of divisors of found
                c.insert(a[i]/j);
                if(d.find(j)!=d.end())
                c.insert(j);
            
         }
 
     }

     //for(auto &x:c)cout<<x<<" ";cout<<endl;

       for(auto &x:c)
       {
          if(b.find(x)==b.end())divisor+=d[x];
          else p-=d[x];
          
       }

       

       for(auto &x:c)b.insert(x);
       //cout<<divisor<<" "<<p<<endl;
      
//  cout<<cnt<<endl;
//  cout<<p<<endl;
     ans+=(((ll)(pow(2,cnt)-1LL)%mod*binpow(2,p))%mod*a[i])%mod;
   //  cout<<ans/a[i]<<endl;
 ans%=mod;
  
     for(int j=1;j<=divisor;j++)
     {
          ans+=((((fact[divisor]*(inv(fact[j],mod))%mod*inv(fact[divisor-j],mod))%mod)
          %mod*((binpow(2,p-divisor))*a[i])%mod)%mod)%mod;
     }

      ans%=mod;

  }

  ans%=mod;
 cout<<ans<<endl;


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

fact.push_back(1);
for(int i=1;i<2000;i++)fact.push_back((i*fact[i-1])%mod);


for(int i=1;i<1900;i++){fact[i]*=fact[i-1];fact[i]%=mod;}

solve();
return 0;
}