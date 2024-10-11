/*
Playing Div.3, easy edition
*/
#include <bits/stdc++.h>
#define ll long long
#define rep(i,m,n) for (auto i=m;i<=n;i++)
#define reb(i,m,n) for (auto i=m;i>=n;i--)
#define rv(i,vt) for (auto i:vt)
#define ii pair<ll,ll>
#define vi vector<ll>
#define F first
#define S second
#define pb push_back
using namespace std;
const ll N=1e6+5,mod=1e9+7;
ll n,k,c,a[N];
map<ll,ll> mi,ma;
void solo()
{
    cin>>n>>k;
    mi.clear();
    ma.clear();
    rep(i,1,n) 
    {
        cin>>a[i];
        if (mi[a[i]]==0) mi[a[i]]=i;
        ma[a[i]]=i;
    }
    while (k--){
        ll l,r;
        cin>>l>>r;
        ll x=ma[r],y=mi[l];
        if (x && y && y<x){
            cout<<"YES";
        }
        else cout<<"NO";
        cout<<"\n";
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll ts=1;
   cin>>ts;
   while (ts--){
       solo();
       cout<<endl;
   }
}