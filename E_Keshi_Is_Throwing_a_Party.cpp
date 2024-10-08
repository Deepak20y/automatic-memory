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
       vector<pair<int,int>>a;
          int ans=1;
       for(int i=0;i<n;i++)
       { 
        int x,y;cin>>x>>y;
         
           if(n-i-1>x)x=n-i-1-x;
           else x=0;

           if(i>y)y=i-y;
           else y=0;
           
           if(x+y!=n-1)
           a.push_back({x,y});

       }
       n=a.size();


    map<int,int>rich,poor;
       
       for(int i=0;i<n-1;i++)
       {
            a[i+1].first=max(a[i].first,a[i+1].first);
       }

    
      for(int i=n-1;i>=1;i--)
      {
         a[i-1].second=max(a[i-1].second,a[i].second);
      }
      
      for(auto &[x,y]:a)cout<<x<<' '<<y<<endl;cout<<endl;





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