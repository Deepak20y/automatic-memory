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
    ll b1,c1,d1;
    cin>>b1>>c1>>d1;
       vector<ll>b(65,0),c(65,0),d(65,0),a(65,0);



    for(int i=0;i<=61;i++)
    {
        if((1LL<<i)&b1)b[i]++;
        if((1LL<<i)&c1)c[i]++;
         if((1LL<<i)&d1)d[i]++;
    }
 bool ok=true;
 //for(auto &x:b)cout<<x<<" ";cout<<endl;
    for(int i=0;i<=61;i++)
    {
        if(b[i]==0&&c[i]==0)a[i]=d[i];
        else if(b[i]==1&&c[i]==0)
        {
            if(d[i]==0)ok=false;
            else a[i]=d[i];
        }
        else if(b[i]==1&&c[i]==1)
        {
           if(d[i]==1)a[i]=0;
           else a[i]=1;

        }
        else{
            if(d[i]==1)ok=false;
        }

    }

    if(!ok)cout<<-1<<endl;
    else{
   
   ll ans=0LL;
   for(int i=0;i<=61;i++)ans|=(1LL<<i)*a[i];
   cout<<ans<<endl;

    }
 


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}