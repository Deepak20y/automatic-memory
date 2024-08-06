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
string ans;
int n,k;
void find(string t)
{
  while(t.size()<k)t+=t;
  while(t.size()>k)t.pop_back();
 ans=min(ans,t);
}


 void solve(){
    cin>>n>>k;
    string s;cin>>s;
    
    for(int i=0;i<k;i++)
    {
         ans.push_back('z');
    }
       
     int n,k;cin>>n>>k;
       
       while(s.size()>0)
       {
          find(s);
          s.pop_back();
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