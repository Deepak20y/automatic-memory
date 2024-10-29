#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    vector<pair<int,int>>ans;
    
    vector<int>b;
    b.push_back(0);
    b.push_back(1);
    
    for(int i=2;i<n;i++)
    {
        ans.push_back({1,3});
        b.push_back(i);
        sort(b.begin(),b.end());
        for(int j=0;j<10;j++)
        {
            for(int k=0;k+1<3;k++)
            {
                 if(a[b[k]]>=a[b[k+1]])swap(b[k],b[k+1]);
            }

        } 
         // for(auto &x:b)cout<<x<<" ";cout<<endl;
        vector<int>c;
        c.push_back(b[0]);
        c.push_back(b[2]);
         b.clear();
        b.push_back(c[0]);
        b.push_back(c[1]);  
        
    }

    sort(b.begin(),b.end());
    //for(auto &x:b)cout<<x<<" ";cout<<endl;

     if(a[b[0]]<=a[b[1]]){
        cout<<ans.size()<<endl;
        for(auto &[x,y]:ans)cout<<x<<" "<<y<<endl;
    
     }
     else cout<<-1<<endl;
   
   
   
   
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