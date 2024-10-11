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
       int n,m;cin>>n>>m;

       vector<vector<int>>a(n+2,vector<int>(m+3,2));

  
  for(int i=1;i<=min(n,m);i++)a[i][i]=3;

   if(m<n)
   { 
     for(int i=m+1;i<=n;i++)a[i][1]=3;

   }
   else if(n<m){
    for(int i=n+1;i<=m;i++)a[1][i]=3;
   
   }
 


   for(int i=1;i<=n;i++)
   {for(int j=1;j<=m;j++)
   {
     cout<<a[i][j]<<" ";
   }

   cout<<endl;

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