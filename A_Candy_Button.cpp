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
        int c;cin>>c;
         int cnt=0;
         int ans=1;
        for(int i=0;i<n;i++)
        {   int m;cin>>m;
            if(c+cnt<=m){cnt=m;ans++;}
        }



cout<<ans<<endl;
return;
}
int main()
{

solve();
return 0;
}