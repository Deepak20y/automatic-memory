#include <iostream>
#include<set>
#include<vector>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
 
 struct pt
 {
    vector<ll>c;
    ll sum;
 };
struct segment
{
    int sz;
    vector<pt> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
            pt ab ;
            ab.sum=0LL;
        ab.c.assign(42,0LL);
        tree.assign(2*sz+10,ab);
    }

    void initial(int i, pt v, int x, int lx, int rx)
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
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

  pt merge(pt &a,pt &b)
   {   pt d;
       d.sum=0LL;
       d.c.assign(42,0LL);

        vector<ll>e(42,0LL),f(42,0LL);
        for(int i=1;i<=40;i++){e[i]=a.c[i];f[i]=b.c[i];}
    
        for(int i=40;i>=1;i--){e[i-1]+=e[i];}

       
         for(int i=1;i<=39;i++)d.sum+=f[i]*e[i+1];
         d.sum+=a.sum+b.sum;

         for(int i=1;i<=40;i++)d.c[i]+= a.c[i]+b.c[i];

       return d;
   }

  

    pt calc(int l, int r, int x, int lx, int rx)
    { 
        if (r <= lx || rx <= l)
            { pt ac; ac.sum=0LL;
             ac.c.assign(42,false);
              
                return ac;
            }
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        pt a=calc(l, r, 2 * x + 1, lx, m);
        pt b=calc(l, r, 2 * x + 2, m, rx);
        return merge(a,b);
        
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
         pt a;
         a.c.assign(42,0LL);
          a.c[m]=1;
          a.sum=0LL;
        tee.initial(i, a, 0, 0, tee.sz);
    }
    
    for (int i = 0; i < q; i++)
    {
        
         int type;cin>>type;
         if(type==2)
         {
             int mp,qp;
             cin>>mp>>qp;
             mp--;
            pt a;
         a.c.assign(42,0LL);
         a.sum=0LL;
          a.c[qp]=1;
             tee.initial(mp,a,0,0,tee.sz);
         }
         else {  
             int l,r;cin>>l>>r;
    

             pt b=tee.calc(l-1,r,0,0,tee.sz);
             
              int cnt=0;
              cout<<b.sum<<endl;
            
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