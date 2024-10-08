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
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
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
        return max(s1 ,s2);
    }

    int find(int k, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        int m = (rx + lx) / 2;
        int var=calc(lx,m,0,0,sz);
        if(k<=var)
        {
           return find(k,lx,m);
        }
        else return find(k,m,rx);
       
    }
};

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    segment tee;
    tee.build(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        tee.initial(i, m, 0, 0, tee.sz);
    }
    
    for (int i = 0; i < q; i++)
    {
        
         int type;cin>>type;
         if(type==1)
         {
             int mp,qp;
             cin>>mp>>qp;
             tee.initial(mp,qp,0,0,tee.sz);
         }
         else { int m;
        cin>>m;
            int p=tee.calc(0,n,0,0,tee.sz);
          if(p<m)cout<<-1<<endl;
          else{
              p=tee.find(m,0,n);
              
                 cout<<p<<endl;
            
          }

         }
    }
 
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}