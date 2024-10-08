#include<bits/stdc++.h>
using namespace std;


void solve()
{
    
    vector<int>a(3);
    
    for(int i=0;i<3;i++)
    { 
        cin>>a[i];
        
    }
     int cnt=0;
    sort(a.begin(),a.end(),greater<int>());
    
    if(a[0]-a[1]-a[2]>1)cout<<"NO"<<endl;
    else cout<<"Yes"<<endl;
   
   
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