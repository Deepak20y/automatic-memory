#include<bits/stdc++.h>
using namespace std;

using ll=long long;
void solve()
{
    int n;cin>>n;
    ll k;cin>>k;
     vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
     bool ok=true;
     ll p=a[0];
    for(int i=0;i<n-1;i++)
    { 
        if(a[i]!=a[i+1])ok=false;
        p=gcd(p,a[i+1]);
    }
    if(ok){cout<<0<<endl;return;}
  
   int sp=0;
   int st=n-1;
   for(int i=0;i<n;i++)
   {
       if(a[i]!=k){sp=i;break;}
   }
   
   for(int i=n-1;i>=0;i--)
   {
       if(a[i]!=k){st=i;break;}
   }
   
   ok=true;
    
    for(int i=sp;i<st;i++)
    if(a[i]!=a[i+1])ok=false;
    
    if(p%k==0||ok)cout<<1<<endl;
    else cout<<2<<endl;
    
   
   return; 
}

int main()
{
    
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);

int t;
cin>>t;
while(t--)
solve();
return 0;

}