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
  string t;cin>>t;
 int n=s.size();
  int j=0;
  int m=t.size();

  for(int i=0;i<n;i++)
  {
       if(j==m)continue;

       if(s[i]==t[j])j++;
       else if(s[i]=='?'){s[i]=t[j];j++;}
  }
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')s[i]='a';
    }

    if(j==m)
    {
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }
    else cout<<"NO"<<endl;


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