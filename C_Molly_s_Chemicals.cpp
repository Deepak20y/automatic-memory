#include<iostream>
#include<vector>
#include<map>
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
      map<ll,int>a;
      vector<ll>check;  
 ll ans=0LL;
 ll sum=0LL;
 int n;cin>>n;
  ll k;cin>>k;
  
  
    check.push_back(1);
    if(k==1)k=k;
    else if(k==-1)
    {  
        check.push_back(-1);

    }
    else{
         ll p=k;
        while(abs(p)<=1e15)
        {
            check.push_back(p);
            p*=k;
        }

    }

    //for(auto &x:check)cout<<x<<" ";cout<<endl;

    a[0]=1;
 for(int i=0;i<n;i++)
 {
     ll m;cin>>m;
     sum+=m;
     
     for(auto &x:check)
     {    
         if(a.find(sum-x)!=a.end())
          ans+=a[sum-x];
     }
 a[sum]++;

 }

  cout<<ans;




return;
}
int main()
{

solve();
return 0;
}