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
       string s;cin>>s;
       int n=s.size();
       vector<int>a(n,-1);
       vector<int>b(n,-1);
      
      stack<int>c;
      
      for(int i=0;i<n;i++)
      {  
         if(s[i]=='(')c.push(i);
         else if(!c.empty()){
             
             a[i]=c.top();
             c.pop();
        //    cout<<i<<" "<<a[i]<<endl;


           if(s[a[i]-1]==')'&&b[a[i]-1]!=-1)
           {
                b[i]=b[a[i]-1];

           }
           else b[i]=a[i];
            
         }

      }
  

 map<int, int, greater<int>> d;
d[0]=1;
  for(int i=0;i<n;i++)
  {
     if(b[i]!=-1)
     { // cout<<i<<" "<<b[i]<<endl;
          d[i-b[i]+1]++;  
     }
  }
 
 for(auto &[x,y]:d){cout<<x<<" "<<y<<endl;return;}
  
      








return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}