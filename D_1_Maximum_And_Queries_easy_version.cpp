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

 bool ok(ll mid,ll k)
 {
      ll need=0LL;
   for(int i=0;i<a.size();i++)
   {
       ll sp=0LL;
      if(mid>a[i]){need+=mid-a[i];continue;}
      else 
      for(int j=0;j<=21;j++)
      {
          
          if(a[i]&(1<<j)){sp+=(1<<j);cout<<1;}
          else cout<<0;
          
          if(sp==mid)break;
          if(sp>mid){
           // cout<<sp+1<<" "<<(1<<(j+1))<<" ";
           cout<<endl;
            if(sp+1==(1<<(j+1)))sp=mid;
            else sp-=(1<<j);
       cout<<i<<"->"<<sp<<endl;
            break;
            
            }
            
        
          
      }
         
        need+=mid-sp;
 
   }


 cout<<mid<<" "<<need<<endl;cout<<endl;cout<<endl;

   if(need<=k)return true;
   else return false;

 }
 
 void solve(){
       int n;
       cin>>n;
       a.resize(n);
      int q;cin>>q;
       for(int i=0;i<n;i++)cin>>a[i];
   
   //for(auto &x:a)cout<<x<<" ";cout<<endl;
       
       

       ll mid,low,k,high;

    //    while(q--)
    // {  cin>>k;
    //     low=0;
    //     high=1e18+1e16;
    //    for(int i=0;i<70&&high>low;i++)
    //    {

    //      if(high>low)
    //      {
    //          mid=(high+low)/2LL;
    //          if(ok(mid,k))low=mid;
    //          else high=mid;
    //      }
    //    }

    //  cout<<low<<"\n";

    // }

    cerr<<ok(637468,3)<<endl;
 
 for(int i=21;i>=0;i--)
 {
    if((1<<i)&1172209)cout<<1;
    else cout<<0;
 }
 cout<<endl;
  for(int i=21;i>=0;i--)
 {
    if((1<<i)&637468)cout<<1;
    else cout<<0;
 }
 cout<<endl;

  for(int i=21;i>=0;i--)
 {
    if((1<<i)&465931)cout<<1;
    else cout<<0;
 }
 cout<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}