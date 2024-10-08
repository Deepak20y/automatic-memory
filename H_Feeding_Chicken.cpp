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
        int m;cin>>m;
          int k;cin>>k;
        vector<char>ch;
        for(char b='a';b<='z';b++)ch.push_back(b);
        for(char b='A';b<='Z';b++)ch.push_back(b);
        for(char b='0';b<='9';b++)ch.push_back(b);
       
        char farm[n+5][m+5];
        int rice=0;

       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++){cin>>farm[i][j];if(farm[i][j]=='R')rice++;}
       }
        // for(int i=1;i<=n;i++)
        // for(int j=1;j<=m;j++)
        // {
        //     cout<<farm[i][j];
        //     if(j==m)cout<<endl;
        // }
        //for(auto &x:ch)cout<<x<<" ";cout<<endl;
        //cout<<rice<<endl;

        //return;
       vector<int>c(k,rice/k);
        int mp=rice%k;

       int ij=k-1;
        while(mp--){c[ij]++;ij--;}
 
      //for(auto &x:c)cout<<x<<" ";cout<<endl;return;
   
   // return;
        
       int im=1;
       char curr='9';
       bool ok=true;

       while(!c.empty())
       {

         if(ok)
         {
            for(int j=1;j<=m;j++)
            {
               if(farm[im][j]=='R')c[c.size()-1]--;
               farm[im][j]=ch.back();
                curr=farm[im][j];
              
                if(c[c.size()-1]==0){c.pop_back();ch.pop_back();}
                   if(c.size()==0)break;
            }
            
          ok=false;
         }
         else{

           for(int j=m;j>=1;j--)
            {
               if(farm[im][j]=='R')c[c.size()-1]--;
               farm[im][j]=ch.back();
                 curr=farm[im][j];
             
                if(c[c.size()-1]==0){c.pop_back();ch.pop_back();}
                    if(c.size()==0)break;
            }

            ok=true;

         }



         im++;
       }
        
          for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
          if(farm[i][j]=='.')farm[i][j]=curr;
       }


       for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
          cout<<farm[i][j];
          if(j==m)cout<<'\n';
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