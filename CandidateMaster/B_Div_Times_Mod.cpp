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
        int k;cin>>k;
       ll ans=1e17;
    ll p,q, num;
       for(int i=1;i*i<=n;i++)
       {   
         
           if(n%i==0)
           {
              if(n%i==i)
              {
                 p=i;
                 q=n/i;

               num=p*k+q;

               if((num/k)*(num%k)==n)ans=min(ans,num);

              }
              else{
                
                p=i;
                 q=n/i;

               num=p*k+q;

               if((num/k)*(num%k)==n)ans=min(ans,num);


                 p=n/i;
                 q=i;

               num=p*k+q;

               if((num/k)*(num%k)==n)ans=min(ans,num);



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