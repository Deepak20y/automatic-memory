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
       int n,k;cin>>n>>k;


     if(n==1)
     {
        cout<<1<<endl<<1<<endl;
     }
     else{

         int p=k-1;
         int st=n-k;

        if(p==0||st==0){cout<<-1<<endl;return;}
         
        if(p==1&&st==1)
        {  cout<<3<<endl;
           cout<<1<<" "<<k<<" "<<k+1<<endl;
        }
        else if(p==1)
        {
             if(st%2!=0)
             {
                cout<<3<<endl;
                cout<<1<<" "<<k<<" "<<k+1<<endl;
             }
             else cout<<-1<<endl;
        }
        else if(st==1)
        {
             if(p%2!=0)
             {
                cout<<3<<endl;
                cout<<1<<" "<<k<<" "<<k+1<<endl;
             }
             else cout<<-1<<endl;

        }
        else{ 
              vector<int>ans;
              
              if(p%2==0)
              {
                ans.push_back(1);
                ans.push_back(k-1);
              }
              else ans.push_back(1);

              ans.push_back(k);


              if(st%2==0)
              {
                ans.push_back(k+1);
                ans.push_back(k+2);
              }
              else ans.push_back(k+1);

          cout<<ans.size()<<endl;
          
          for(auto &x:ans)cout<<x<<" ";cout<<endl;


        }

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