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

     
   ll p=1;

   while(true)
   {  
 //cout<<n<<" "<<p<<endl;
     if(n<p)
     {
        cout<<"Vladik";
        break;
     }
       n-=p;
     p++;
     if(m<p)
     {
        cout<<"Valera";
        break;
    
     }

     m-=p;

 p++;


   }








return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}