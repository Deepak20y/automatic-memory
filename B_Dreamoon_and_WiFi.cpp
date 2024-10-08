#include<bits/stdc++.h>
using namespace std;
using ll =long double;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
 
  int recur(int i, string &s,int x,int &sp)
  { 
    if(i>=s.size())
    {  
        if(x==sp)return 1;
        else return 0;
        
    }
     int ans=0;
     
     if(s[i]=='?')
     {
        ans=recur(i+1,s,x+1,sp)+recur(i+1,s,x-1,sp);
     }
     else if(s[i]=='+')
     {
        ans=recur(i+1,s,x+1,sp);
     }
     else 
     {  ans=recur(i+1,s,x-1,sp);

     }

     return ans;

  }
 void solve(){
       
       string pt;
       cin>>pt;
     int tp=0;
       for(int i=0;i<pt.size();i++)
       if(pt[i]=='+')tp++;
       else tp--;

   string s;
   cin>>s;
    int cnt=0;
   
     for(int i=0;i<s.size();i++)
     if(s[i]=='?')cnt++;
    
   ll stp=1.0;
     while(cnt--)stp*=2.0;
     
     ll mp=recur(0,s,0,tp);
    //cout<<mp<<" "<<stp<<endl;
     cout<<setprecision(10)<<mp/stp;



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}