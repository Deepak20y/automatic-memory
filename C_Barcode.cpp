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
        int m;cin>>m;
        int x,y;cin>>x>>y;
       vector<int>a(m+1,0),b(m+1,0);
  
   for(int i=0;i<n;i++)
   { 
     
     for(int j=1;j<=m;j++)
     {
         char c;cin>>c;
         if(c=='#')a[j]++;
         else b[j]++;
     }
         
   }

   for(int i=1;i<m;i++){a[i+1]+=a[i];b[i+1]+=b[i];}

  vector<int>dp1(m+1,1e9);
  vector<int>dp2(m+1,1e9);

  dp1[0]=0;
  dp2[0]=0;



                             



      // dp1[j] denotes the last index  in the segment is white 
       // dp2[j] denotes the last index  in the segment is black

    
    for(int i=1;i<=m;i++)
    {
        for(int j=max(i-y,0);j<=i-x;j++)
        {  
           dp1[i]=min(dp1[i],dp2[j]+a[i]-a[j]);
           dp2[i]=min(dp2[i],  dp1[j]+b[i]-b[j]);
        
        }

    }



    

 cout<<min(dp1[m],dp2[m])<<endl;


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}