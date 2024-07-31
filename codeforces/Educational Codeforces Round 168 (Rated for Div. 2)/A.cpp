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
bool ok=false;

  for(int i=0;i<n-1;i++)
  {
    if(s[i]==s[i+1])
    {
        ok=true;
    }

  }
  

  if(ok)
  { 

    for(int i=0;i<n;i++)
    {  cout<<s[i];
        if(ok&&i+1<n&&s[i]==s[i+1])
        {
              ok=false;

              for(char c='a';c<='z';c++)if(s[i]!=c){cout<<c;break;}
        }

    }


  }
  else{
     for(char c='a';c<='z';c++)if(s[0]!=c){cout<<c;break;}
     cout<<s;

  }
 cout<<endl;
  

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