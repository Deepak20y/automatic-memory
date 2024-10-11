#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
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

  
 vector<vector<ll>>dp,ap;
  
 // i is the total dishes chosen till now and j denotes the last chosen dish 
 void solve(){
              
       int n;cin>>n;
      int m;cin>>m;
      int k;cin>>k;
    dp.assign(1<<n,vector<ll>(n+1,0));
     ap.assign(n,vector<ll>(n,0));
  ll ans=0LL;
      vector<int>b(n);
       for(int i=0;i<n;i++)
       {
         cin>>b[i];
         ans=max(ans,(ll)b[i]);
         dp[1<<i][i]=b[i];
       }
  
   for(int i=0;i<k;i++)
   {
        int x,y;cin>>x>>y;
        x--;y--;
        int p;cin>>p;
        ap[x][y]=p;
   }
   vector<int>a;

   for(int i=0;i<(1<<n);i++)
   {    
        if(__builtin_popcount(i)<m)
        a.push_back(i);
   }


   
   sort(a.begin(),a.end(),[&](const int &a,const int &b)
   {
            return __builtin_popcount(a)> __builtin_popcount(b);
   });


    a.pop_back();
   

 
   
   while(!a.empty())
   {   
      int p=a.back();
          vector<int>c,d;
          
      for(int i=0;i<n;i++)
      {
         if(p&(1<<i))c.push_back(i);
         else d.push_back(i);
      } 
     
         for(auto &x:d)
      {   
             int sp=(1<<x)|p;
             for(auto &y:c)
         {   
           dp[sp][x]=max(dp[sp][x],dp[p][y]+ap[y][x]+b[x]);
           ans=max(ans,dp[sp][x]);
         }

      }
     a.pop_back();
 
   }

   cout<<ans<<endl;






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}