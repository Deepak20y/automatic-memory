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

    int  n,m;cin>>n>>m;
     int a[n+4][m+4];
   
     map<int,pair<int,int>>b;

     for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)cin>>a[i][j];

      for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){int p;cin>>p;b[p].first=i;b[p].second=j;}

         vector<int>c(5,0);
   

      vector<int>c(n*m+2);
        int row=0;
        int col=0;
      for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
           int p=0;
           int q=0;
          if(i!=b[a[i][j]].first)
          { p++;
            
          }
          if(j!=b[a[i][j]].second){q++;
          }

            c[2*p+q]++;

      }

     // cout<<row<<" "<<col<<endl;

       bool ok=true;

       if(c[1]%(2*m)!=0)ok=false;
       if(c[2]%(2*n)!=0)ok=false;








       





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