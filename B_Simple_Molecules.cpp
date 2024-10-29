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
       int a,b,c;
       cin>>a>>b>>c;

       for(int i=0;i<=a;i++)
       {
           
           int m=b-(a-i);// bond between 1 and 2 
           int n=c-i; //bond between 1 and 3

           if(m==n&&m>=0)
           {
             cout<<a-i<<" "<<m<<" "<<i<<endl;
             return;
           }
         

       }

       cout<<"Impossible";





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}