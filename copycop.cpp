#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        map<int,int>mapmax;
        map<int,int>mapmin;
        for(int i=1;i<=n;i++){
            int temp; cin>>temp;
            mapmax[temp]=i;
            if(mapmin[temp] == 0) mapmin[temp] = i;
        }
        for(int i=0;i<k;i++){
            int a,b;cin>>a>>b;
            if(mapmin[a]==0 || mapmin[b]==0){
                cout<<"NO"<<endl;
                continue;
            }
            if(mapmin[a]<mapmax[b]){
                cout<<"YES"<<endl;
                continue;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}