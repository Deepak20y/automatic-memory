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
       
       int l,r;
       cin>>l>>r;
 int ans=0;
    int sp=l;
    for(int i=l;i<=r;i++)
    {

        int maxp=0;
        int minp=9;
        int m=i;
        
        while(m>0)
        {
            maxp=max(maxp,m%10);
            minp=min(minp,m%10);
            m/=10;
        }

        //cout<<maxp<<" "<<minp<<endl;
        if(ans<maxp-minp){ans=maxp-minp;sp=i;}
        if(ans==9)break;
    }

    cout<<sp<<endl;




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