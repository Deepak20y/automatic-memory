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
       int n;
       cin>>n;
       
       int a25=0,a50=0;
       bool ok=true;

       for(int i=0;i<n;i++)
       {
         int m;cin>>m;
         if(m==25)a25++;
         else if(m==50)
         {
             if(a25<=0)ok=false;
             else a25--;
             a50++;
         }
         else{
             
              if(a25>=1&&a50>=1)
              {
                a25--;
                a50--;
              }
              else if(a25>=3){
            a25-=3;
              }
              else ok=false;

         }

       }

       if(ok)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}