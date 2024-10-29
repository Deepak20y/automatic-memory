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
       
       string s,t;
       cin>>s;
       cin>>t;

       int n=s.size();
       int m=t.size();
       int j=0;
       int cnt=0;
       int cnt2=0;
       
        
         int maxp=0;
        for(int i=0;i<m;i++)
        {
             int k=i;
              int cnt=0;
            for(int j=0;j<n&&k<m;j++)
            {
               if(s[j]==t[k]){cnt++;k++;}
          
            }
            maxp=max(maxp,cnt);
        }

    
       if(maxp==m)
       {
         cout<<n<<endl;
       }
       else{
         cout<<m-maxp+n<<endl;
       }





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