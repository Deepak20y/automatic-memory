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
        
        int n;cin>>n;

        vector<ll>a;
     int cnt=0;
      ll maxp=0;
        for(int i=0;i<n;i++)
        {
            int m;cin>>m;
          
          if(m%2==0)cnt++;

          if(m%2==0)a.push_back(m);
          else   maxp=max((ll)m,maxp);
        }
     

     if(cnt==n||cnt==0){cout<<0<<endl;return;}
    
    sort(a.begin(),a.end());

      n=a.size();
      cnt=0;
    
   for(int i=0;i<a.size();i++)
   { 
      if(a[i]>maxp){maxp+=a[n-1];cnt++;}
      maxp+=a[i];
      cnt++;
   }

   cout<<cnt<<endl;












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