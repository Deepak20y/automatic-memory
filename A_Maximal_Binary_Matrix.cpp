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
       int n;cin>>n;int k;cin>>k;

        vector<vector<int>>a(n+3,vector<int>(n+4,0));

        
         int p=k;
         for(int i=1;i<=n;i++)
         for(int j=1;j<i;j++)
         {
             if(i!=j&&k>1)
             {
                p-=2;
             }
         }
      

         for(int i=1;i<=n&&k>0;i++)
         {
               
               p--;
         }

            if(p>0){cout<<-1<<endl;return;}

  int diag=n;
  int total=n*n-n;


      a.assign(n+3,vector<int>(n+4,0));
                    
         for(int i=1;i<=n;i++)
         for(int j=1;j<=i;j++)
         {
             if(k<=0)break;

             if(i==j){a[i][j]=1;k--;}
             else if(i!=j&&k>=2)
             {
                a[i][j]=1;
                a[j][i]=1;

                k-=2;
             }


         }









return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}