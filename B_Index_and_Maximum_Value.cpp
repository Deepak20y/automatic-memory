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
       int q;cin>>q;
       //vector<int>a(n);
       ll maxp=0;
       for(int i=0;i<n;i++){ll m;cin>>m;maxp=max(maxp,m);}

    while(q--)
    {
         char ch;
         cin>>ch;
         int l,r;cin>>l>>r;
         if(ch=='+')
         {
            if(l<=maxp&&r>=maxp)maxp++;
         }
         else 
         {
             if(l<=maxp&&r>=maxp)maxp--;
         }

         cout<<maxp<<" ";
    }
       
cout<<endl;




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