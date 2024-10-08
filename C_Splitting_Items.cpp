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
       int k;cin>>k;
     vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];

       sort(a.begin(),a.end(),greater<int>());

       for(int i=0;i<n;i+=2)
       {     if(i==n-1)break;
           int p=a[i]-a[i+1];
           if(p<=k)
           {
             a[i+1]=a[i];
             k-=p;
           }
           else 
           {
             a[i+1]+=k;
             k=0;
           }
       }

 ll score=0LL;

   for(int i=0;i<n;i++)
   {
     if(i%2==0)score+=a[i];
     else score-=a[i];
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