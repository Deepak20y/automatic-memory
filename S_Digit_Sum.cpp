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
     int division;       
ll recur(int pos,int sum,int small)
{

     if(pos>=a.size()){
         return !bool(sum%division);
     }

     int p=small?9:a[pos];
     ll ans=0LL;
     for(int i=0;i<=p;i++)
     {
         
         recur(pos,(sum+i)%division,small||i!=a[pos]);

     }

     
 return ans;


}


 void solve(){
       
       string s;cin>>s;
       cin>>division;
      

       for(int i=0;i<s.size();i++)
       {
         a.push_back(s[i]-'0');
       }

       cout<<recur(0,0,pos)





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}