#include<bits/stdc++.h>
using namespace std;


void solve()
{
    
    int ans=1;
    
     int n;cin>>n;
     string s;cin>>s;
     int cnt=0;
     
     int sp=0;
    
    string t=s;
    reverse(t.begin(),t.end());
           if(s[0]==s[n-1])ans=max(ans,n);

    while(s.size()>0&&s[s.size()-1]!=s[0])
    {
        s.pop_back();
       
    }
   
    while(t.size()>0&&t[t.size()-1]!=t[0])
    {
        t.pop_back();
       
    }

    ans=max(ans,(int)s.size());
      ans=max(ans,(int)t.size());
    cout<<ans<<endl;
   
   return; 
}

int main()
{
    
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);

int t;
cin>>t;
while(t--)
solve();
return 0;

}