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
 set<int>d;
 int pos;
   map<int,int>c;
 void perform(char ct)
 { 
         
        auto it=d.upper_bound(max(pos,c[pos]));
        auto pt=d.lower_bound(min(pos,c[pos]));
      //   return ;
         if(ct=='D')
        { queue<int>q; 
         if(it==d.end())
           {auto mt=pt;
           mt--;
           pos=*mt;}
           else pos=*it;
           
         for(auto st=pt;st!=it;st++)
         {
             q.push(*st);
         }
     
     while(!q.empty())
     {
        d.erase(q.front());
        q.pop();
     }
            
        }
        else{
          pt=d.lower_bound(pos);
        //  cout<<pos<<" ";
          if(ct=='R')
          {
               pt++;
               pos=*pt;
          }
          else{ 
            
                  pt--;
                  pos=*pt;
          }

         // cout<<pos<<endl;


        }
      
    

 }


 void solve(){
        int n;cin>>n;
        int m;cin>>m;
        cin>>pos;
        pos--;
        string s;cin>>s;

        string t;cin>>t;
       stack<int>a;
     
       
        for(int i=0;i<n;i++)
        { d.insert(i);
            if(s[i]=='(')a.push(i);
            else{ 
                int p=a.top();
                a.pop();
                c[i]=p;
                c[p]=i;
            }
        }
 

        for(int i=0;i<m;i++)
        { 
            perform(t[i]);    
        }
 
 string ans="";
        for(auto &x:d)
        { 
            if(x==min(x,c[x]))ans.push_back('(');
            else ans.push_back(')');
        }

        cout<<ans;








return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}