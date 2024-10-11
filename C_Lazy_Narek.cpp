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

 unordered_map<char,int>b;

  b['n']=1;
  b['a']=1;
  b['r']=1;
  b['e']=1;
  b['k']=1;
 vector<char>a{'n','a','r','e','k'};

  

  vector<int>dp(6,-1e9);
  vector<int>dp2(6,-1e9);
  dp2=dp;
  dp[0]=0;
  dp2[0]=0;
  
   int sm=0;
   int maxp=0;
   int cnt=0;
   int bc=0;

   for(int i=0;i<n;i++)
   {
           string s;
           cin>>s;
     sm=0; cnt=0;
      bc=0;
     for(int j=0;j<m;j++)
     {
        if(s[j]==a[sm]){sm++;cnt++;}
        else bc+=b[s[j]];
         
         if(sm==5)sm=0;
     }


    dp2[cnt%5]=max(dp2[cnt%5],dp[0]-bc+(cnt/5)*5-cnt%5);
// cout<<bc<<" "<<dp[4]<<" "<<cnt<<endl;

  
    sm=1; cnt=0;
      bc=0;
     for(int j=0;j<m;j++)
     {
        if(s[j]==a[sm]){sm++;cnt++;}
        else bc+=b[s[j]];
         
         if(sm==5)sm=0;
     }
    
    if(dp[1]!=-1e9)
    dp2[cnt%5]=max(dp2[cnt%5],dp[1]-bc+(cnt/5)*5-cnt%5+1);


    sm=2; cnt=0;
      bc=0;
     for(int j=0;j<m;j++)
     {
        if(s[j]==a[sm]){sm++;cnt++;}
        else bc+=b[s[j]];
         
         if(sm==5)sm=0;
     }
    
      if(dp[2]!=-1e9)
    dp2[cnt%5]=max(dp2[cnt%5],dp[2]-bc+(cnt/5)*5-cnt%5+2);


    sm=3; cnt=0;
      bc=0;
     for(int j=0;j<m;j++)
     {
        if(s[j]==a[sm]){sm++;cnt++;}
        else bc+=b[s[j]];
         
         if(sm==5)sm=0;
     }

     if(dp[3]!=-1e9)
    dp2[cnt%5]=max(dp2[cnt%5],dp[3]-bc+(cnt/5)*5-cnt%5+3);


    sm=4; cnt=0;
      bc=0;
     for(int j=0;j<m;j++)
     {
        if(s[j]==a[sm]){sm++;cnt++;}
        else bc+=b[s[j]];
         
         if(sm==5)sm=0;
     }


     if(dp2[4]!=-1e9)
    dp2[cnt%5]=max(dp2[cnt%5],dp[4]-bc+(cnt/5)*5-cnt%5+4);
 
    
     for(int j=0;j<5;j++)
     {
          dp[j]=max(dp[j],dp2[j]);
     }
     

     //for(auto &x:dp)cout<<x<<" ";cout<<endl;
     
   

       dp2=dp;


   }
   
  for(int i=0;i<5;i++)maxp=max(dp[i],maxp);

  cout<<maxp<<endl;






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