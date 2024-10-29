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
       string s="";
       for(int i=0;i<n;i++)
       {
         string p;cin>>p;
         s+=p;
       }


       n=s.size();
       int cnt=0;
       for(int i=0;i<n-1;i++)
       {
         if(s[i]==s[i+1])cnt++;
       }

       cout<<cnt+1<<endl;





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}