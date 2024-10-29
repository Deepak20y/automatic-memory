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
       vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];
       int ans=0;
       sort(a.begin(),a.end());
     
     if(k==1||n<=3)
     {
        cout<<2*a[n-1]+a[0]+a[n-2]<<endl;
     }
     else{

        int p=a[0]+a[n-1]+a[n-2];
          int st=k-1;
        for(int i=n-3;i>=0;i--)
        {  st--;
           if(st==0)
           {
            p+=a[i];
            break;
           }
           
        }

        cout<<p<<endl;



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