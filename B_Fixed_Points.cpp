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
       vector<int>a(n+1,-1);
       vector<int>b(n);
       for(int i=0;i<n;i++)
       { 
        cin>>b[i];
            
       }
       bool ok=true;
       int cnt=0;
       for(int i=0;i<n;i++)
       { 
          if(b[i]==i){cnt++;continue;}
          a[b[i]]=i;
          if(a[i]==b[i]&&ok){cnt+=2;ok=false;}
         
       }

       if(ok)cout<<min(cnt+1,n)<<endl;
       else cout<<cnt<<endl;

    






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}