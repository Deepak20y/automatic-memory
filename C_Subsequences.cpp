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

    void initial(int i, ll v, int x, int lx, int rx)
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
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
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
        return s1 + s2;
    }

   
};

 void solve(){
        int n;
        cin>>n;
        int k;cin>>k;
        
       vector<pair<int,ll>>a(n);
     for(int i=0;i<n;i++){cin>>a[i].first;a[i].first--;a[i].second=1;}
    //  for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;cout<<endl;

        
        for(int i=0;i<k;i++)
        {
           segment tee;
            tee.build(n);
            
          for(int j=0;j<n;j++)
          {   
             ll p=tee.calc(0,a[j].first,0,0,tee.sz);
            //cout<<a[j].first<<" "<<p<<endl;
             tee.initial(a[j].first,a[j].second,0,0,tee.sz);
             a[j].second=p;
          }

         // for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;cout<<endl;

        }

        ll ans=0LL;

        for(int i=0;i<n;i++)ans+=a[i].second;
        
        cout<<ans;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}