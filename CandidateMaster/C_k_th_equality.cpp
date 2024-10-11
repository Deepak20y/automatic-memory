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

vector<int>aa,bb,cc;
bool bin(ll mid,ll lowest,ll lot, ll k)
{
      
}

 void solve(){
       ll a,b,c,k;
       cin>>a>>b>>c>>k;


     
          ll m=pow(10,a)-1;     
          ll st=pow(10,a-1);

          ll n=pow(10,b)-1;
          ll qt=pow(10,b-1);
           

          ll pt=pow(10,c)-1;
          ll mt=pow(10,c-1);


 // cout<<m<<" "<<st<<" "<<n<<" "<<qt<<" "<<pt<<" "<<mt<<endl;

       for(int i=st;i<=m;i++)
       {
            ll p=pt-i;         //it is the maximum b when a=i;
            ll q=mt-i;         // it is the minimum b when a=i;
             
           // cout<<p<<" "<<q<<endl;
            ll mmp=min(n,p)-max(q,qt)+1;
            // cout<<p<<" "<<endl;
            mmp=max(mmp,0LL);
            //cout<<i<<" + "<<qt+k<<" = "<<i+qt+k<<endl;
        
          if(mmp>=k)
          {   
             cout<<i<<" + "<<max(q,qt)+k-1<<" = "<<i+max(q,qt)+k-1<<endl;
             return ;
          }
          else k-=mmp;
    

          
       } 
       // cout<<k<<endl;
              cout<<-1<<endl;




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