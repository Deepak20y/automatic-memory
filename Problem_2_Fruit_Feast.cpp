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
 int a,b;
 bool dp[5000005]={false};


 void solve(){
      freopen("feast.in","r",stdin);
      freopen("feast.out","w",stdout);

       int n;
       cin>>n;
       cin>>a>>b;
       dp[0]=true;

 // cout<<a<<" "<<b<<endl;

       int maxp=0;

       for(int i=0;i<=n;i++)
       {  
          if(i+a<=n)
          {dp[i+a]|=dp[i];
            
          }

          if(i+b<=n)
          {
            dp[i+b]|=dp[i];
            

          }
       }

      // for(int i=1;i<=10;i++)cout<<dp[i]<<" ";cout<<endl;
        vector<int>c;
        for(int i=1;i<=n;i++)
        {
          if(dp[i])c.push_back(i);    
        }

   // if(dp[n]){cout<<n<<endl;return;}

       for(int i=1;i<=n;i++)
       { 
           if(dp[i])maxp=max(maxp,i);

            if(dp[i]||((2*i<=n)&&(dp[2*i]))||((2*i+1<=n)&&(dp[2*i+1])))
            {
               
                int low=upper_bound(c.begin(),c.end(),n-i)-c.begin();
                 
                 if(low!=0)low--;
                 //cout<<i<<" "<<c[low]<<" "<<maxp<<endl;
                 if(i+c[low]<=n)
                 {
                    maxp=max(maxp,i+c[low]);
                 }
                

            }

       }

      std:: cout<<maxp<<endl;

     


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}