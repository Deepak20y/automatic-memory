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
 int a[805][805];
 ll n,k;
 int b[805][805];
 int dp[805][805];
  int ans;
  bool bin(int mid)
  {
        //cout<<mid<<endl;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(a[i][j]<=mid)b[i][j]=1;
    else b[i][j]=0;
    ll mt;
     mt=(k*k)/2LL+1;
    // cout<<mt<<endl;
      if(k%2==0)
      {mt=k*k-mt+1;}
   

     for(int i=0;i<=n;i++){dp[i][0]=0;dp[0][i]=0;}


     for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
     dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+b[i][j];
 bool ok=false;
     //cout<<mid<<endl;
     for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
     {
          int p=i+k-1;
          int q=j+k-1;
       if(i+k-1>n||j+k-1>n)continue;
          int st=dp[p][q]-dp[i-1][q]-dp[p][j-1]+dp[i-1][j-1];
        //  cout<<st<<" "<<mt<<endl;
      if(st>=mt)
           {ok=true;
    ans=min(ans,mid);
    //if(mid==1)cout<<st<<" "<<mt<<endl;
           }

     }
   // cout<<endl;
     return ok;


  }


 void solve(){
    cin>>n>>k;
ans=1e9;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>a[i][j];
    }
    

   int low=0;
   int high=1e9;
   int mid;

   for(int i=0;i<=35;i++)
   {

    if(high>=low)
    {
           mid=(high+low)/2;
           if(bin(mid))high=mid;
           else low=mid;
    }

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