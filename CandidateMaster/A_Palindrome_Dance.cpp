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
        int x,y;cin>>x>>y;

        int ans=0;

        vector<int>a(n);

        for(int i=0;i<n;i++)cin>>a[i];
        //for(auto &x:a)cout<<x<<" ";cout<<endl;

        int l=0;
        int r=n-1;
        while(l<=r)
        {      
            if(l==r&&a[l]==2){ans+=min(x,y);break;}

           if(a[l]==a[r]&&a[l]==2)ans+=2*min(x,y);
           else if(a[l]!=a[r]&&max(a[l],a[r])==1){cout<<-1<<endl;return;}
           else if(a[l]!=a[r]&&max(a[l],a[r])==2)
           {
              int p=min(a[l],a[r]);
              if(p==0)ans+=x;
              else ans+=y;
              
           }
     l++;r--;
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