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
       int m;cin>>m;
       int q;cin>>q;

       vector<int>a;


     for(int i=0;i<m;i++)
     {
         int m;cin>>m;
         a.push_back(m);
     }
       sort(a.begin(),a.end());
    while(q--)
    {
      int pos;cin>>pos;


        int p=upper_bound(a.begin(),a.end(),pos)-a.begin();


          if(p==m)
          {
             int st=a[m-1];
             cout<<n-a[m-1]<<endl;
          }
          else if(a[0]>pos)
          {
              cout<<a[0]-1<<endl;
          }
          else{

            int sp=a[p-1];
               p=a[p];

             cout<<(p-sp)/2<<endl;

          }



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