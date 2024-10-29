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
       int m,n;
       cin>>n>>m;

       vector<vector<int>>a(n+4,vector<int>(m+4,0));

       for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)cin>>a[i][j];

    
     for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     {  
         int p=-1;

         bool ok=false;
        if(i-1>=1)p=max(p,a[i-1][j]);
        if(j-1>=1)p=max(p,a[i][j-1]);
        if(i+1<=n)p=max(p,a[i+1][j]);
        if(j+1<=m)p=max(p,a[i][j+1]);
        
        if(p>=a[i][j])continue;
        a[i][j]=p;
     }

     for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     {
         cout<<a[i][j]<<" ";
         if(j==m)cout<<endl;
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