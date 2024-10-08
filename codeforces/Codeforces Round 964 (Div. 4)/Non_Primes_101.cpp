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

 vector<int>prime;
 void fill()

{

     for(int i=2;i<=200;i++)
     { bool ok=true;
         
         for(int j=2;j*j<=i;j++)
         {
            if(i%j==0){ok=false;break;}
         }
         if(ok)prime.push_back(i);
     }
}
 void solve(){
        
         vector<int>a[105];
         int n;cin>>n;
        for(int i=1;i<=n;i++)
        { 
            int  m;cin>>m;
            a[m].push_back(i);
        }
       
    
       

      for(int i=1;i<=100;i++)
      {
          if(a[i].size()==0)continue;

          for(int j=2;j<=100;j++)
          { 
             if(a[j].size()==0)continue;
             if(i==j&&a[i].size()<2)continue;
             if(i==j&&a[i].size()>1)
             {
               if(!binary_search(prime.begin(),prime.end(),i+j)){cout<<a[i][0]<<" "<<a[i][1]<<endl;return;}
             }
             else if(!binary_search(prime.begin(),prime.end(),i+j)){cout<<a[i][0]<<" "<<a[j][0]<<endl;return;}

          }


      }

 cout<<-1<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
fill();
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}