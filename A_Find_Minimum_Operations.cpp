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
       
       ll n,k;cin>>n>>k;


       if(k==1||n<k)cout<<n<<endl;
       else{
     
           ll cnt=0;

           while(n>0)
           {
               ll p=k;
             while(n>=p*k)
             {
                p*=k;
             }

             if(n>=p)
             {n-=p;cnt++;}

             if(n>0&&n<k){cnt+=n;n=0;}

           }
             
             cout<<cnt<<endl;



       }





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