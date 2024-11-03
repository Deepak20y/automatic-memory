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
       int n,m;cin>>n>>m;
       int q;cin>>q;
  vector<vector<ll>>a(m,vector<ll>(n,0LL));

       for(int j=0;j<n;j++)
       {
         for(int i=0;i<m;i++)cin>>a[i][j];
       }


       for(int i=0;i<m;i++)
       for(int j=0;j<n-1;j++)a[i][j+1]|=a[i][j];

    //    for(int i=0;i<4;i++)
    //    for(int j=0;j<3;j++)
    //    {
    //     cout<<a[i][j]<<" ";
    //     if(j==2)cout<<endl;
    //    }

     
        
        while(q--)
        {
               int pm;cin>>pm;
                int ans=0;
                int sp=n-1;
             for(int i=0;i<pm;i++)
             {
                 ll r,cost;
                 char c;
                 cin>>r>>c>>cost;
                 r--;
                 if(c=='>')
                 {
                     int p=upper_bound(a[r].begin(),a[r].end(),cost)-a[r].begin();
                     ans=max(ans,p);
                 }
                 else{
                    int tp=upper_bound(a[r].begin(),a[r].end(),cost-1)-a[r].begin();
                    tp--;
                    sp=min(sp,tp);
                 }
             } 

             

            
             if(sp==-1||ans==n||sp<ans){cout<<-1<<endl;continue;}

            cout<<ans+1<<endl;
   

             

        }

return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}