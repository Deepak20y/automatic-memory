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
       

 vector<int>a{0,1,2,3};

  vector<int>b(4);
  for(int i=0;i<4;i++)cin>>b[i];
   int ans=0;
 
do 
 {
     if((a[0]<=1&&a[1]<=1)||(a[2]>=2&&a[3]>=2))continue;
      if((a[2]<=1&&a[3]<=1)||(a[0]>=2&&a[1]>=2))continue;

      //for(auto &x:a)cout<<x<<" ";cout<<endl;
      int cnt1=0;
      int cnt2=0;
      
      if(a[0]<2)
      {
          if(b[a[0]]>b[a[1]])cnt1++;
          if(b[a[1]]>b[a[0]])cnt2++;
      }
      else{
          if(b[a[0]]>b[a[1]])cnt2++;
          if(b[a[1]]>b[a[0]])cnt1++;
      }

      if(cnt1>cnt2)cnt1=1;
      else cnt1=0;

       int pt1=0;
       int pt2=0;

      if(a[2]<2)
      {
          if(b[a[2]]>b[a[3]])pt1++;
          if(b[a[3]]>b[a[2]])pt2++;
      }
      else{
          if(b[a[2]]>b[a[3]])pt2++;
          if(b[a[2]]<b[a[3]])pt1++;
      }
        
        if(pt1>pt2)pt1=1;
        else pt2=0;

      if(cnt1==1&&pt1==1)ans++;

      



 }
 while(next_permutation(a.begin(),a.end()));
   
   cout<<ans/4<<endl;



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