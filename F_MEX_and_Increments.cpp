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
      vector<int>a(n);
     vector<ll>sp(n+4,0);
      for(int i=0;i<n;i++){cin>>a[i];sp[a[i]]++;}
       vector<ll>ans(n+1,-1);
          

        //  for(int i=0;i<=n;i++)sp[i+1]+=sp[i];


       bool ok=true;

       ll moves=0LL;
     multiset<int>b;

     //for(auto &x:sp)cout<<x<<" ";cout<<endl;
       for(int i=0;i<=n;i++)
       {
               

               
               if(i==0)
               {
                        ans[i]=sp[i];
               }
               else if(ok)
               {

                     ans[i]=moves+sp[i];
               }


               if(sp[0]==0)ok=false;
               else if(sp[i]==0&&b.size()==0)ok=false;
               else{
                     while(sp[i]--)b.insert(i);
                       auto sp=b.end();
                         sp--;
                         //cout<<i<<" "<<*sp<<endl;
                        moves+=i-*sp;

                        b.erase(sp);

                     
               }

               if(!ok)break;
               

       }

       for(auto &x:ans)cout<<x<<" ";cout<<'\n';





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