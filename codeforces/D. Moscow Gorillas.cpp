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

  vector<int>a(n),b(n);

  map<int,int>pos1,pos2;

  for(int i=0;i<n;i++){cin>>a[i];pos1[a[i]]=i;}
  for(int i=0;i<n;i++){cin>>b[i];pos2[b[i]]=i;}

  ll ans=0LL;
 ll cnt=0LL;
  for(int i=0;i<n;i++)
  { cnt=0LL;
     while(i<n&&a[i]!=1&&b[i]!=1){cnt++;i++;}

     ans+=((cnt)*(cnt+1LL))/2LL;
  }
  
  int c1=n,c2=0;

  

  for(int i=0;i<n;i++)
  {
         if(a[i]==1||b[i]==1){c1=min(i,c1);c2=max(i,c2);}
  }

  for(int i=2;i<=n-1;i++)
  {   cnt=0;
      if((c1<=pos1[i]&&pos1[i]<=c2)||(c1<=pos2[i]&&pos2[i]<=c2))
      {
        ans=ans;
      }
      else{
         ll st1=0;
         ll st2=0;
         if(max(pos1[i],pos2[i])<=c1)
         {
                 st1=max(n-1-c2,0);st2=max(c1-max(pos1[i],pos2[i])-1,0);
         }
         else if(min(pos1[i],pos2[i])>=c2)
         {
            st1=max(c1,0);st2=max(min(pos1[i],pos2[i])-c2-1,0);
         }
         else{

            st1=max(c1-min(pos1[i],pos2[i])-1,0);st2=max(max(pos1[i],pos2[i])-c2-1,0);
         }
         // cout<<cnt<<" "<<i<<endl; 
     st1++;
     st2++;
      ans+=st1*st2;

      }
  
         c1=min(pos1[i],c1);
         c2=max(pos1[i],c2);
          c1=min(pos2[i],c1);
         c2=max(pos2[i],c2);

       //  cout<<c1<<" "<<c2<<endl;

  }
  

 ans++;
 std::cout<<ans<<endl;

return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}