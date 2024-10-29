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
       

       map<int,int,greater<int>>a,b;

    

       for(int i=0;i<n;i++)
       {
           int m;cin>>m;

           while(m%2==0)m/=2;
           a[m]++;
           

       }


       for(int i=0;i<n;i++)
       {
           int m;cin>>m;

           while(m%2==0)m/=2;
           b[m]++;   
       }


       for(auto &[x,y]:b)
       {
          
          while(y>0)
          {
            int p=x;

            while(p>0)
            {
                if(a.find(p)!=a.end())
                {
                    if(a[p]>0)
                    {
                        a[p]--;
                        break;
                    }
                }
                p/=2;
            }


            y--;
          }

       } 

       bool ok=true;

       for(auto &[x,y]:a)
       {
            if(y!=0)ok=false;
       }

       if(ok)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;

      
     

     

      






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