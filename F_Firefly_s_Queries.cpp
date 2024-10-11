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


   ll fin(vector<ll>&a,ll l,ll r)
   {  
    int n=a.size();

   
 // l and r are in the same segments  it tells they are in same segments
    
        

        ll p=l/n;  // tells the number of times we have to rotate means 
                  // elememts are going to back so we have to move in the front

         l=l%n;
         r=r%n;

         l+=p;     // this is the number of moves we are moving forward
         r+=p;
       ll ans=0LL;

      // cout<<l<<" "<<r<<endl;return 0;
         if(r<n||l>=n)
         {  
             r%=n;
             l%=n;
          
            ans=a[r];
            if(l-1>=0)ans-=a[l-1];
            return ans;
         }
         else {
            
               r%=n;
               l%=n;
               ans+=a[r];
               ans+=a[n-1];
               if(l-1>=0)ans-=a[l-1];
               return ans;
             
         }

        



    
  

     



   }
 void solve(){
    
      ll n;cin>>n;
     int q;cin>>q;
      vector<ll>a(n);
 
   ll sum=0LL;

      for(int i=0;i<n;i++)cin>>a[i];
       
       for(int i=0;i<n-1;i++)a[i+1]+=a[i];
       sum=a[n-1];

      while(q--)
      {
         ll l,r;cin>>l>>r;

          l--;
          r--;
          if(l/n==r/n)
          {
            cout<<fin(a,l,r)<<endl;
          }
          else{
             
             ll p1=l;
             ll p2=(l/n)*n+n-1;

             ll q1=(r/n)*n;
             ll q2=r;
             
             cout<<fin(a,p1,p2)+fin(a,q1,q2)+sum*max(r/n-l/n-1,0LL)<<endl;


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