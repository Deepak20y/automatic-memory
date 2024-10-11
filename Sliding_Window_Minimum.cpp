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

         deque<int>a;
         vector<int>b(n);

         for(int i=0;i<n;i++)cin>>b[i];
      

       for(int i=0;i<k-1;i++)
       { 
              
            while(!a.empty()&&b[i]<=b[a.back()])a.pop_back();
            a.push_back(i);
       }
        
 vector<int>ans;
       for(int i=k-1;i<n;i++)
       {

         while(!a.empty()&&b[i]<=b[a.back()])a.pop_back();
          a.push_back(i);
            
          cout<<b[a.front()]<<" ";
        // cout<<i<<" "<<i-k+1<<" "<<a.front()<<endl;
          if(a.front()==i-k+1)a.pop_front();

       }

      cout<<endl;







return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}