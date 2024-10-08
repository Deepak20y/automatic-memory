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
         int n;
       cin>>n;
       string s;cin>>s;
     
     vector<pair<char,int>>a;
 string ans="";
 char ab='a';
  for(int i=0;i<26;i++)
  { 
     a.push_back({ab,0});
     ab++;
  }


     
     for(int i=0;i<n;i++)
     {

        a[s[i]-'a'].second++;
     }
 // for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;
     bool ok=true;

      while(ok)
    {  ok=false;
        for(int j=0;j<26;j++)
        {
              if(a[j].second>0)
              {
                a[j].second--;
                ok=true;
                ans.push_back(a[j].first);
              }

        }
     
    }

    cout<<ans<<endl;



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