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
       
       string s;cin>>s;
       int n=s.size();

       int k;cin>>k;
      int cnt=0;
    for(int i=0;i<n;i++)
    {
       if(s[i]!='?'&&s[i]!='*')cnt++;

    }

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
       
       string s;cin>>s;
       int n=s.size();

       int k;cin>>k;
      int cnt=0;
    for(int i=0;i<n;i++)
    {
       if(s[i]!='?'&&s[i]!='*')cnt++;

    }

    

  string ans="";
    if(cnt<k)
    {     
           for(int i=0;i<n;i++)
           {
                if(s[i]=='*')
                {   int p=k-cnt;
                    while(p>0)
                    {
                        ans.push_back(s[i-1]);
                        p--;
                        cnt++;
                    }
                }
                else if(s[i]!='?')ans.push_back(s[i]);
           }

           if(ans.size()!=k)ans="Impossible";
    }
    else if(cnt==k)
    {
       for(int i=0;i<n;i++)
           {
                if(s[i]!='?'&&s[i]!='*')ans.push_back(s[i]);

           }
    }
    else{
        
        for(int i=0;i<n;i++)
           {
                if(s[i]=='*'||s[i]=='?')continue;
                else if(cnt>k&&i+1<n&&(s[i+1]=='*'||s[i+1]=='?')){cnt--;}
                else ans.push_back(s[i]);
           }

       if(ans.size()!=k)ans="Impossible";

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
  string ans="";
    if(cnt<k)
    {     
           for(int i=0;i<n;i++)
           {
                if(s[i]=='*')
                {   int p=k-cnt;
                    while(p>0)
                    {
                        ans.push_back(s[i-1]);
                        p--;
                        cnt++;
                    }
                }
                else if(s[i]!='?')ans.push_back(s[i]);
           }

           if(ans.size()!=k)ans="Impossible";
    }
    else if(cnt==k)
    {
       for(int i=0;i<n;i++)
           {
                if(s[i]!='?'&&s[i]!='*')ans.push_back(s[i]);

           }
    }
    else{
        
        for(int i=0;i<n;i++)
           {
                if(s[i]=='*'||s[i]=='?')continue;
                else if(cnt>k&&i+1<n&&(s[i+1]=='*'||s[i+1]=='?')){cnt--;}
                else ans.push_back(s[i]);
           }

       if(ans.size()!=k)ans="Impossible";

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