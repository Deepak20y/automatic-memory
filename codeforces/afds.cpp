#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

struct segment
{
    int sz;
    vector<int> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, 0);
    }

    void initial(int i, int v, int x, int lx, int rx)
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

  
    int calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return 0;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        int s1 = calc(l, r, 2 * x + 1, lx, m);
        int s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    
};

const int mod=1e9+7;

void solve()
{
    int n; int m;cin>>n;cin>>m;
    segment tee;
    tee.build(m);
 vector<int>a(n);
 map<int,int>b;
    for(int i=0;i<n;i++){cin>>a[i];b[a[i]]++;tee.initial(i,1,0,0,tee.sz);}

    ll ans=0LL;
   int  prev=m;
     ll maxp=0LL;
     ll idx=1;
     set<int>c;
     bool ok=true;
    for(int i=0;i<n;i++)
    {     
        if(b[a[i]]==1){
            if(c.find(a[i])==c.end())maxp=a[i];
            if(c.find(a[i])==c.end())ans+=maxp*idx;
            idx++;prev--;
            c.insert(a[i]);
        }
        else if(prev==tee.calc(0,m,0,0,tee.sz))
         {
            maxp=max((ll)a[i],maxp);
         }
       
         ok=true;
         b[a[i]]--;
         if(b[a[i]]==0)tee.initial(a[i]-1,0,0,0,tee.sz);
       
         
    }

    ans+=maxp;
    cout<<ans<<endl;
  

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}