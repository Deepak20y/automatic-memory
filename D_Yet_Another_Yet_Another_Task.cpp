#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
// remove maximum value from segment
//
void solve()
{
   int n;
   cin >> n;
   set<int> c[62];

  
  int ans=0;

  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  for(int j=-30;j<=30;j++)
  {   int sum = 0;
   for(int i=0;i<n;i++)
  {
    if(a[i]<=j)
    {
      sum+=a[i];
      ans=max(ans,sum-j);
    }
    else sum=0;

    sum=max(sum,0);

  }

  }

  cout<<ans<<endl;

   

   return;
}
int main()
{
   std::ios::sync_with_stdio(false);
   std::cin.tie(nullptr);
   std::cout.tie(nullptr);

   solve();
   return 0;
}