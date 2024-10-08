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
       vector<int>a(n);
       set<int>d;
       for(int i=0;i<n;i++){cin>>a[i];d.insert(a[i]);}

       vector<int>ans(n,1e5+9);

        set<int>c; 
        for(int i=0;i<a[n-1];i++)
        {
            c.insert(i);
        }
        
        for(int i=0;i<n;i++)
        {
            if(c.find(a[i])!=c.end())c.erase(a[i]);
        }

        
        for(int i=0;i<n;i++)
        {

             if(c.size()>0)
             {
                ans[i]=*c.begin();
                c.erase(c.begin());
             }
             
            

            if(i!=n-1&&a[i]!=a[i+1])
            {
                c.insert(a[i]);
            }
        }
       
       bool ok=true;
       int jk=0;
       vector<bool>mex(n+5,false);
       for(int i=0;i<n;i++)
       { 
            if(ans[i]<=n)mex[ans[i]]=true;

            while(mex[jk])jk++;
           
            if(jk!=a[i])ok=false;
       }


       if(ok)
       {
         for(auto &x:ans)cout<<x<<" ";
       }
       else cout<<-1<<endl;


return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}