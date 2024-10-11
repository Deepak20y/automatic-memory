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
 vector<int>score;

 ll sol(string &s,char &a)
 {
      map<ll,ll>b;
      int n=s.size();
      ll ans=0LL;
          ll sum=0LL;
      for(int i=0;i<n;i++)
      {
            if(a!=s[i])
            {sum+=score[s[i]-'a'];

            }
            else{
               
               
                ans+=b[sum];
                sum+=score[a-'a'];
    
                 b[sum]++; 
                
            }
       
      }

      
    

      return ans;


 }



 void solve(){
       
       for(int i=0;i<26;i++)
       {
         int m;cin>>m;
         score.push_back(m);
       }

       //for(auto &x:score)cout<<x<<" ";cout<<endl;


       string s;cin>>s;

       ll ans=0LL;
       for(char a='a';a<='z';a++)
       {
          ans+=sol(s,a);
         // break;
       }

      

    
       cout<<ans<<endl;

       




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}