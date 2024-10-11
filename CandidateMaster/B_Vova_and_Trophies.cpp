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

       string s;cin>>s;

       vector<int>a(n,0);
    int cnt=0;
       for(int i=0;i<n;i++)
       { 
              if(s[i]=='G'){a[i]=1;cnt++;}

                if(a[i]==0)continue;
                else if(i>0)a[i]+=a[i-1];
       }

       
       int p=0;
       for(int i=n-1;i>=0;i--)
       {
           if(a[i]==0){p=0;continue;}
            p=max(a[i],p);

          a[i]=p;
             
       }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {  
           ans=max(ans,a[i]);

           if(a[i]<cnt)ans=max(ans,a[i]+1);

            if(i-1>=0&&i+1<n)
            {
                if(a[i]==0)
                {  ans=max(ans,a[i+1]+a[i-1]);
                   //cout<<a[i+1]+a[i-1]<<endl;
                  if(a[i+1]+a[i-1]<cnt)ans=max(ans,a[i+1]+a[i-1]+1);

                }


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