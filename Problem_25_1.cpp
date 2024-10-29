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
        int q;cin>>q;
       vector<vector<int>>a(n,vector<int>(26,0));
       vector<vector<int>>b(n,vector<int>(26,0));

   string s;cin>>s;
   string  t;cin>>t;

   for(int i=0;i<n;i++)
   {
      a[i][s[i]-'a']++;
      b[i][t[i]-'a']++;
   }


   for(int i=0;i<n-1;i++)
   { 
     
     for(int j=0;j<26;j++)
     {
        a[i+1][j]+=a[i][j];
         b[i+1][j]+=b[i][j];
     }
   }   

   
    int ans=0;
   while(q--)
   {
        int l,r;cin>>l>>r;
        l--;r--;
       ans=0;
        for(int i=0;i<26;i++)
        {
            int p1=a[r][i];

            int p2=b[r][i];

            //cout<<p1<<" "<<p2<<endl;

            if(l-1>=0)p1-=a[l-1][i];
            if(l-1>=0)p2-=b[l-1][i];

            if(p2<p1)ans+=p1-p2;


        }

        cout<<ans<<endl;


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