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
      

      string ans="";

  int i=n/2;
  int j=n/2+1;
      if(n%2==0){i--;j--;}

 while(ans.size()<n)
 {

       if(i>=0)
       ans.push_back(s[i]);

       if(j<n)
       ans.push_back(s[j]);
       i--;
       j++;
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