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
       vector<int>a(n+m+1),b(n+m+1);

       for(int i=0;i<n+m+1;i++)cin>>a[i];
      for(int i=0;i<n+m+1;i++)cin>>b[i];



       int test=0;
       int pro=0;

      for(int i=0;i<n+m+1;i++)
      {
        if(a[i]>b[i])pro++;
        else test++;
      }

    // cout<<test<<" "<<m<<' '<<pro<<" "<<n<<endl;

      if(test>m)
      { 
         vector<int>p,st;
         for(int i=0;i<n+m+1;i++)
         {
            if(a[i]<b[i]&&p.size()<=m)p.push_back(i);
            else st.push_back(i);
         }

        //  for(auto &x:p)cout<<x<<" ";cout<<endl;
        //  for(auto &x:st)cout<<x<<" ";cout<<endl;

         ll tester=0LL;
         ll Programmer=0LL;

        for(auto &x:p)
        {
             tester+=b[x];
        }

        for(auto &x:st)
        {
             Programmer+=a[x];
        }

        for(int i=0;i<n+m+1;i++)
        {
            if(binary_search(st.begin(),st.end(),i))
            {
              cout<<tester-b[p.back()]+Programmer+a[p.back()]-a[i]<<" ";
            }
            else{ 
                  cout<<tester-b[i]+Programmer<<" ";
            }
        }
      cout<<endl;

      }
      else
      {
         vector<int>p,st;
      
         for(int i=0;i<n+m+1;i++)
         {
            if(a[i]>b[i]&&p.size()<=n)p.push_back(i);
            else st.push_back(i);
         }

        //  for(auto &x:p)cout<<x<<" ";cout<<endl;
        //  for(auto &x:st)cout<<x<<" ";cout<<endl;

         ll tester=0LL;
         ll Programmer=0LL;

        for(auto &x:st)
        {
             tester+=b[x];
        }

        for(auto &x:p)
        {
             Programmer+=a[x];
        }

        for(int i=0;i<n+m+1;i++)
        {
            if(binary_search(st.begin(),st.end(),i))
            {
              cout<<Programmer-a[p.back()]+tester+b[p.back()]-b[i]<<" ";
            }
            else{ 
                  cout<<Programmer-a[i]+tester<<" ";
            }
        }
      cout<<endl;

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