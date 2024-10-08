#include<bits/stdc++.h>
using namespace std;

 
 int ff1(string &t)
 {  if(t.size()==0)return 0;
     set<pair<char,int>>a;
     
     for(int i=0;i<t.size();i++)
     {
         a.insert({t[i],i});
     } 
      
   //   for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;cout<<endl;

    // return 0;
      int mp=0;
     vector<char>bc{'b','a','c','k'};
     while(true)
    {
         queue<char>q;

     for(int i=0;i<4;i++)
     {
        q.push(bc[i]);
     }
      queue<pair<char,int>>pq;
          int p=-1e9;
         auto st=a.begin();
         while(!q.empty()&&st!=a.end())
         {
             st=a.upper_bound({q.front(),p});
             if(st==a.end())break;
             if(st->first!=q.front())break;

             p=st->second;
             q.pop();
             pq.push({st->first,st->second});
         }
         
         if(!q.empty())break;
         else{
            
            while(!pq.empty()){a.erase({pq.front().first,pq.front().second});pq.pop();}
             
             a.insert({'b',--mp});
         }
        
     
    }


    // for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;
    // cout<<a.size()<<endl;
     return a.size();
 }

  int ff2(string &t)
 {  if(t.size()==0)return 0;
     set<pair<char,int>>a;
     
     for(int i=0;i<t.size();i++)
     {
         a.insert({t[i],i});
     } 
      int mp=t.size()+1;
     vector<char>bc{'f','r','o','n','t'};
     while(true)
    { queue<char>q;

     for(int i=0;i<5;i++)
     {
        q.push(bc[i]);
     }
      queue<pair<char,int>>pq;
          int p=-1e9;
         auto st=a.begin();
         while(!q.empty()&&st!=a.end())
         {
             st=a.upper_bound({q.front(),p});
             if(st==a.end())break;
             if(st->first!=q.front())break;

             p=st->second;
             q.pop();
             pq.push({st->first,st->second});
         }
         
         if(!q.empty())break;
         else{
            
            while(!pq.empty()){a.erase({pq.front().first,pq.front().second});pq.pop();}
             
             a.insert({'t',++mp});
         }
         
     
    }

     return a.size();
 }
 

 
void solve()
{ 
    int n;
    cin>>n;
    string s;cin>>s;
    n=s.size();
     string t="";
     string st="";
      int cnt=0;


     set<char>a{'a','b','c','k'};
     set<char>b{'f','r','o','n','t'};
    int ans=0;
     for(int i=0;i<n;i++)
     {
         if(a.find(s[i])!=a.end())t.push_back(s[i]);
         else if(b.find(s[i])!=b.end())st.push_back(s[i]);
         else cnt++;
     }

  // cout<<ff1(t)<<endl;
   cout<<cnt+ff1(t)+ff2(st)<<endl;
    
   
   
   
   
   return; 
}

int main()
{
    
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);

int t;
cin>>t;
while(t--)
solve();
return 0;

}