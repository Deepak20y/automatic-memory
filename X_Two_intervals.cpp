#include<iostream>
using namespace std;
int main()
{
     int l,r,x,y;
     cin>>l>>r>>x>>y;
     l=max(x,l);
     r=min(r,y);
     
     if(r-l>=0)cout<<l<<" "<<r;
     else cout<<-1;
    
    return 0;
}