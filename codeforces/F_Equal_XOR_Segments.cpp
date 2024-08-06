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
 vector<int>a(n);
       for(int i=0;i<n;i++)
       {
               cin>>a[i];
       }
   
   for(int i=0;i<n-1;i++)a[i+1]^=a[i];
     // for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
   set<pair<int,int>>b;

   for(int i=0;i<n;i++)b.insert({a[i],i});
  //for(auto &x:a)cout<<x<<" ";cout<<endl;
   while(q--)
   {
            int l,r;
            cin>>l>>r;

        
           bool ok=false;
           r--;
           l--;
          
           if(r-l>0){
                int p=a[r];
                if(l-1>=0)p^=a[l-1];
 
           //    cout<<p<<endl;
                    int st=0;
                    if(l-1>=0)st=a[l-1];
           
               if(p==0)
               {
                //  auto sp=b.upper_bound({a[r],l-1});
                //   if(sp!=b.end())
                //   { 
                //     if(sp->first==a[r]&&sp->second>l-1&&sp->second<r)ok=true;
                //   }

                 ok=true;
                 
               }
               else{
              
                 auto sp=b.upper_bound({a[r],l-1});
                 int idx=l-1;
                 bool ok1=false;
                 bool ok2=false;
                 if(sp!=b.end())
                 {
                     if(sp->first==a[r]&&sp->second>l-1&&sp->second<r){idx=sp->second;ok1=true;}
                    
                 }


                 sp=b.upper_bound({st,idx});

                 if(sp!=b.end())
                 {
                     if(sp->first==st&&sp->second>idx&&sp->second<r){ok2=true;}
                    // cout<<ok1<<" "<<ok2<<endl;
                    //  cout<<idx<<" "<<sp->second<<endl;
                 }

                 
                 ok=ok1&ok2;

               }

           }
            
               if(ok)cout<<"YES"<<endl;
               else cout<<"NO"<<endl;

   }
   cout<<endl;


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