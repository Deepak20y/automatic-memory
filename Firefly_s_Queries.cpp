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
 
ll su(int l,int r,int change,vector<ll>&b)
{
     int n=b.size();
     ll sum=0LL;
      int p=(l+change)%b.size();
      
      if(l+change<n)
      { 
        if(r+change<n)
        {
            sum+=a[r+change]-a[l+change-1];
        }

      }




}


 void solve(){
       int n;cin>>n;
       int q;cin>>q;
       vector<int>a(n);
        ll sum=0LL;
       for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}

       while(q--)
       { 
         int l,r;cin>>l>>r;

        
         if(r-l+1==n)
         { 
            cout<<sum<<endl;

         }
         else if(r-l+1<n)
         {
            

             if(r/n==l/n)
             {


             }
             else{


             }

         }
         else{

              ll mp=((r-l+1)/n)*sum;

            int p=l/n;
            int l1=l%n;
            int r1=n-1;

            int q=r/n;
            int l2=(r/n)*n;
            int r2=

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