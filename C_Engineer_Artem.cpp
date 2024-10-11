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
int a[105][105];
 void solve(){
       int n,m;cin>>n>>m;


   for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)cin>>a[i][j];

 
 for(int i=0;i<n;i++)
 for(int j=0;j<m;j++)
 {
 
 if(i%2==0)
 {
      if(j%2==0)
      {
         if(a[i][j]%2==1)a[i][j]++;
      }
      else{
        if(a[i][j]%2==0)a[i][j]++;
      }
 }
 else{

   if(j%2==1)
      {
         if(a[i][j]%2==1)a[i][j]++;
      }
      else{
        if(a[i][j]%2==0)a[i][j]++;
      }
 }



 }


 for(int i=0;i<n;i++)
 for(int j=0;j<m;j++){cout<<a[i][j]<<" ";if(j==m-1)cout<<endl;}






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