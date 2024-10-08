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
       
        vector<int>a(4);


        for(int i=0;i<4;i++){cin>>a[i];}
      int cnt=0;

      if((a[0]>a[2]&&a[1]>a[3])||(a[0]>a[2]&&a[1]==a[3])||(a[0]==a[2]&&a[1]>a[3]))cnt++;
       if((a[0]>a[3]&&a[1]>a[2])||(a[0]>a[3]&&a[1]==a[2])||(a[0]==a[3]&&a[1]>a[2]))cnt++;

     
      if((a[1]>a[2]&&a[0]>a[3])||(a[1]>a[2]&&a[0]==a[3])||(a[1]==a[2]&&a[0]>a[3]))cnt++;
       if((a[1]>a[3]&&a[0]>a[2])||(a[1]>a[3]&&a[0]==a[2])||(a[1]==a[3]&&a[0]>a[2]))cnt++;
   

 cout<<cnt<<endl;
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