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

    for(int i=0;i<n;i++)
    {
         int m;cin>>m;
         a.insert(m);
    }


    //if(a.size()==1){cout<<"Alice"<<endl;return;}

      vector<int>b;

      for(auto &x:a)b.push_back(x);

      n=b.size();
      
      int c=1;
          if(b[0]==1)c=0;

          //for(auto &x:b)cout<<x<<" ";cout<<endl;

        if(b.size()==1||b[0]>1){cout<<"Alice"<<endl;return;}
      for(int i=1;i<n-1;i++)
      {
            
            if(b[i]-b[i-1]==1)c=1-c;
            else{
               break;
            }
      }
      
      if(c==0)cout<<"Bob"<<endl;
      else cout<<"Alice"<<endl;



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