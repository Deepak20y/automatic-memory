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
ll ans;
bool bin(ll mid,ll g,ll n,ll k)
{

     
     int p=min(n,mid/g+1);
     ll sp=mid+1;
     if(sp-p<=k){ans=mid;return true;}
     else return false;
     
      
  


}
 void solve(){
       int n;cin>>n;
       ans=1;
       ll k;cin>>k;
     ll m=0;
     vector<int>a(n);
       for(int i=0;i<n;i++)
       { 
          cin>>a[i];
          m=gcd(a[i],m);

       }

       ll low=0;
       ll mid;
       ll high=1e10;

        if(n == 1)
    {
    	if(m>= k) cout << k - 1;
    	else cout << k;
        cout<<endl;
    	return;
    }
    if(m == 1)
    {
    	cout << n + k - 1;
        cout<<endl;
    	return;
    }


       for(int i=0;i<70&&high>=low;i++)
       {

         if(high>=low)
         {
             mid=(low+high)/2LL;
            if(bin(mid,m,n,k))low=mid;
            else high=mid;
              
         }
       }

    // if(ans%m==0&&)

 cout<<ans<<endl;


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