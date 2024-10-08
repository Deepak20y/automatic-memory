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

       string s;cin>>s;

       int p=sqrt(n);
       if(p*p!=n){cout<<"NO"<<endl;return;}
 //cout<<p<<endl;
   bool ok=true;
   for(int i=0;i<n;i+=p)
   {
       int j=i;
      if(s[j]!=s[j+p-1]||s[j]!='1')ok=false;
       map<char,int>a;
      // cout<<i<<" "<<endl;
      for( j=i+1;j<i+p-1;j++)
      { 
          a[s[j]]++;
          //cout<<
          
      }
      
     // cout<<i<<" "<<a['0']<<" "<<a['1']<<endl;
 
       if(i==0||i==n-p)
       {
         if(a['1']!=p-2)ok=false;
       }
       else{
        if(a['0']!=p-2)ok=false;
       }


   }
   
   if(ok)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;



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