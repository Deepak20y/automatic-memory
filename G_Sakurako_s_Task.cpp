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
       ll k;cin>>k;
     ll m=0;
       for(int i=0;i<n;i++)
       { 
          int p;cin>>p;
          m=gcd(p,m);

       }

       if(n==1)
       {
          cout<<m-1<<endl;return;
       }

       if(m==1)
       {
           cout<<n+k-1<<endl; return ;
       }
       else{

          vector<ll>a;
          a.push_back(0);

          for(int i=1;i<n;i++)
          {
            a.push_back(a.back()+m);
          }
            //for(auto &x:a)cout<<x<<' ';cout<<endl;
            if(k==m){cout<<k+2<<endl;return;}
            else if(k==m-1){cout<<m+1<<endl;return;}
            else {cout<<k+1<<endl;return;}

          for(int i=0;i<n-1;i++)
          {
              if(a[i]+k>=a[i+1])k-=(a[i+1]-a[i]-1);
              else 
              {  
                if(k==0)k++;
                cout<<a[i]+k<<endl;return;
              }
              
          } 
           if(k==0)k++;
           cout<<a[n-1]+k<<endl;




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