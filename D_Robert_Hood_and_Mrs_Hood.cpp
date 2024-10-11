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
       int n,d,m;
       cin>>n>>d>>m;
       
       vector<int>a(n,0);
       vector<int>b(n,0);

       for(int i=0;i<m;i++)
       { int l,r;
       cin>>l>>r;
       l--;r--;
       a[l]++;
       b[r]++;
       }

       for(int i=0;i<n-1;i++)
       {
        a[i+1]+=a[i];
        b[i+1]+=b[i];
       }

       int br=0,br1=0,mr=0,mr1=1e9;


       for(int i=d-1;i<n;i++)
       {
           int p=a[i];
            
            if(i-d>=0)p-=b[i-d];


            if(br1<p)
            {
                br1=p;
                br=i-d+2;
            }

             if(mr1>p)
            {
                mr1=p;
                mr=i-d+2;
            }


       }

       cout<<br<<" "<<mr<<endl;









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