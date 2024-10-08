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

       set<int>a;

       for(int i=1;i<=500;i++)
       {
           a.insert(i);
       }

    vector<int>b(n);
  
   for(int i=0;i<n;i++)cin>>b[i];
   sort(b.begin(),b.end());
  
  for(auto &x:b)cout<<x<<" ";cout<<endl;
   int ans=0;
   for(int i=0;i<n;i++)
   {
         for(auto &x:a){cout<<x<<" ";if(x>17)break;}
         cout<<endl;
        if(a.find(b[i])!=a.end())
        {
            a.erase(b[i]);
            cout<<b[i]<<" "<<b[i]<<endl;
        }
        else{

          auto  sp=a.lower_bound(b[i]);
          
          if(sp==a.begin())
          {
             ans+=abs(b[i]-*sp);
             a.erase(sp);
           }
           else{
            
             int mp=*sp;
             sp--;
             int qp=*sp;

             if(abs(qp-b[i])<=abs(mp-b[i]))
             {
                ans+=abs(qp-b[i]);
                a.erase(qp);
                cout<<b[i]<<" "<<qp<<endl;
             }
             else{
                ans+=abs(mp-b[i]);
                a.erase(mp);
                cout<<b[i]<<" "<<mp<<endl;

             }

           }


        }


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