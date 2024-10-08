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
        
        ll cost=0LL;
        ll n,k;cin>>n>>k;
        vector<ll>a(k);
       
       for(int i=0;i<n;i++)
       {  int m;cin>>m;
         m--;
         a[m]++;

       }
      
      sort(a.begin(),a.end());
      
      //for(auto &x:a)cout<<x<<" ";cout<<endl;
         cost=k*a[k-1];
          int p=1;
      for(int i=k-1;i>=k/2+k%2;i--)
      {
         ll maxp=a[k-1];
         int sj=min(p,(int)k-1);
          int j=0;
          //cout<<j<<" "<<sj<<" "<<Iendl;
         while(j<sj)
         {
            maxp=max(a[j]+a[sj],maxp);
            j++;
            sj--;
         }
  //   cout<<i<<" "<<maxp<<endl;
         cost=min(cost,(ll)i*maxp);

         
       p+=2;
      }

      cout<<cost;





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}