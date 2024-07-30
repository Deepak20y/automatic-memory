#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

struct segment
{
    int sz;
    vector<ll> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, 0LL);
    }

    void initial( int i, ll v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            initial(i, v, 2 * x + 1, lx, m);
        else
            initial(i, v, 2 * x + 2, m, rx);
        tree[x] = gcd(tree[2 * x + 1], tree[2 * x + 2]);
    }

  
    ll calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return 0LL;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m, rx);
        return gcd(s1, s2);
    }

};


void solve()
{

     int n;cin>>n;
     vector<ll>a(n);
     int ans=1;
     segment tee;
     tee.build(n);
     for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
     
   //for(auto &x:a)cout<<x<<" ";cout<<endl;
     for(int i=0;i<n-1;i++)
     {
         tee.initial(i,abs(a[i]-a[i+1]),0,0,tee.sz);
         //cout<<abs(a[i]-a[i+1])<<" ";
     }
     cout<<endl;

     n--;
      int r=1;

      ll sp;
     for(int l=0;l<n;l++)
     {   if(r==l)r++;
         while(r+1<=n)
         {    sp=tee.calc(l,r+1,0,0,tee.sz);
          
            if(r<=n&&sp>1LL)r++;
            else break;
         }
       // sp=tee.calc(l,r,0,0,tee.sz);
   //cout<<l<<" "<<r<<" "<<sp<<endl;
      if(tee.calc(l,r,0,0,tee.sz)>1LL)ans=max(r-l+1,ans);

     }


     cout<<min(ans,n+1)<<endl;
     //cout<<endl;
     
}
int main()
{
     int t;cin>>t;
     while(t--)
     solve();
}
