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

 vector<int>a;
 vector<bool>b;

 int po(int j)
 {  int len=0;
     while(!b[j])
     {
        b[j]=true;
        j=a[j];
        len++;

     }
     return (len-1)/2;
 }
 void solve(){
  int n;  cin>>n;
    a.resize(n);
    b.assign(n,false);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
  

     int ans=0;

     for(int i=0;i<n;i++)
     {   if(!b[i])
         ans+=po(i);
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