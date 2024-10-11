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

bool ok(vector<ll>&a,ll mid, ll s)
{  

    ll sum=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        sum+=max(a[i]-mid,0LL);
    }
    
    if(sum>=s)return true;
    else return false;
    



}
 void solve(){
       int n;cin>>n;
       ll s;cin>>s;
       vector<ll>a(n);
       ll sum=0LL;
       ll high=1e9;
   for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];high=min(high,a[i]);}
     
     if(sum<s){cout<<-1<<endl;return;}
     else if(sum==s){cout<<0<<endl;return;}
    
    ll low=0;
    
    high+=1;
     ll mid;
     for(int i=0;i<60;i++)
     {


         if(low<=high)
         {
             mid=(high+low)/2;
             if(ok(a,mid,s))low=mid;
             else high=mid;
         }
     }
  
    cout<<low<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}