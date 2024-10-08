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
       string s;
       cin>>s;

    ll score=0LL;
     int cnt=0;
     vector<int>ans;
     for(int i=0;i<n-1;i++)
     {  
        if(s[i]!=s[i+1]){ans.push_back(1);cnt++;}
        else ans.push_back(0);
     }
 
 sort(ans.begin(),ans.end(),greater<int>());

 while(ans.size()>0)
 {
     if(ans.back()==1)cnt--;
     ans.pop_back();
     score+=cnt;
    
 }
 cout<<score<<endl;


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