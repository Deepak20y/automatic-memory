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

bool find(ll  mid,ll n,int p)
{
 ll sp=1LL;
 if(mid==0)return false;
  for(int i=0;i<p;i++)
  {
    if(sp<=n/mid)sp*=mid;
    else return false;
     
  }

  return true;

}

bool pc(ll mid,ll n,int p)
{

   ll sp=1LL;
   for(int i=1;i<=p;i++)sp*=mid;

     return sp<=n;
}

 void solve(){
       ll n;cin>>n;
 
 ll ans=0LL;
 vector<int>a{2,3,5,7,11,13,17};
 
 for(int i=0;i<a.size();i++)
 {

    ll low=0;
    ll high=(ll)1e9+(ll)1e5;
    ll mid;

    for(int j=0;j<60;j++)
    {
        if(high>=low)
        {
            mid=(high+low)/2LL;
            if(find(mid,n,a[i]))low=mid;
            else high=mid;

        }
    }
  
 //if(!pc(low,n,a[i]))low--;
    ans+=low-1LL;

 }

 //cout<<ans<<endl;

 

 vector<int>b{6,10,14,15};

 for(int i=0;i<b.size();i++)
 {

    ll low=0;
    ll high=(ll)1e9+(ll)1e5;
    ll mid;

    for(int j=0;j<60;j++)
    {
        if(high>=low)
        {
            mid=(high+low)/2LL;
            if(find(mid,n,b[i]))low=mid;
            else high=mid;

        }
    }
// if(!pc(low,n,b[i]))low--;
    ans-=low-1LL;

 }

 ans++;





cout<<(ll)ans;
cout<<endl;

cout<<(ll)pow(3,19)<<endl;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}