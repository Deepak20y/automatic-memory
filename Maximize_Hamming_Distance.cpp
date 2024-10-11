#include<bits/stdc++.h>
using namespace std;

using ll=long long int;
void solve()
{
    
   int n;cin>>n;
   int m;cin>>m;
   vector<ll>a(n,0);
   vector<ll>b(n,0);
   vector<ll>c(n,0);
   
   
   for(int i=0;i<m;i++)
   {
       
       string s;cin>>s;
       
       for(int j=0;j<n;j++)
       {
           if(s[j]=='?')c[j]++;
           else if(s[j]=='0')a[j]++;
           else b[j]++;
       }
       
       
   }
    
    // for(auto &x:a)cout<<x<<" ";cout<<endl;
    // for(auto &x:b)cout<<x<<" ";cout<<endl;
    // for(auto &x:c)cout<<x<<" ";cout<<endl;
   
   ll ans=0LL;
   
   
   for(int i=0;i<n;i++)
   {
       if(c[i]==0)ans+=a[i]*b[i];
       else
       {
           if(a[i]>b[i])
           {
               ll p=a[i]-b[i];
               p=min(c[i],p);
               b[i]+=p;
               c[i]-=p;
               
           }
           else if(a[i]<b[i])
           {  
               ll p=b[i]-a[i];
               p=min(c[i],p);
               a[i]+=p;
               c[i]-=p;
               
           }
           a[i]+=c[i]/2+c[i]%2;
            b[i]+=c[i]/2;
            
            ans+=a[i]*b[i];
          
           
           
       }
       
   }
   
   cout<<ans<<endl;
   
   
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