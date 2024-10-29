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
       int n;
       cin>>n;
 int q;cin>>q;
       vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];

      
       while(q--)
       {
           int l,r;cin>>l>>r;
           int px;cin>>px;

            l--;r--;px--;

            int m=px-l;
           // cout<<m<<" "<<px<<endl;
             int cnt=0;
            for(int i=l;i<=r;i++)
            { 
                if(a[px]>a[i])cnt++;
            }

           // cout<<m<<" "<<cnt<<" "<<px<<endl;

            if(m==cnt)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;




       }





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}