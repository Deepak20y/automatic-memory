#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;


struct p
{
     int cnt1,cnt2,cnt3,maxp;
};

struct segment
{
    int sz;
    vector<p> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, {0,0,0,0});
    }

     p merge(p a,p b)
     {
            a.cnt1+=b.cnt1;
            a.cnt2+=b.cnt2;
            a.cnt3+=b.cnt3;

            a.maxp=max({a.cnt1,a.cnt2,a.cnt3});
            return a;
          
     }

    void initial(int i, p v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] =v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            initial(i, v, 2 * x + 1, lx, m);
        else
            initial(i, v, 2 * x + 2, m, rx);
        tree[x] =merge(tree[2 * x + 1],tree[2 * x + 2]);
    }

  

    p calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return {0,0,0,0};
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        p s1 = calc(l, r, 2 * x + 1, lx, m);
        p s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1,s2);
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
         p a{0,0,0,0};
         a.maxp=1;
         if(m==1)a.cnt1++;
         if(m==2)a.cnt2++;
         if(m==3)a.cnt3++;
        tee.initial(i, a, 0, 0, tee.sz);
    }

    while(q--)
    {

         int l,r;cin>>l>>r;

          int pq=r-l+1;
          
           if(pq==1){cout<<"No"<<endl;continue;}
           l--;
                 
               p a=tee.calc(l,r,0,0,tee.sz);
              
              if(pq%2==1)cout<<"No"<<endl;
               else if(pq%2==0&&a.maxp==pq/2)cout<<"Yes"<<endl;
               else cout<<"No"<<endl;

          
    }
    
   
    return;
}
int main()
{
    
  int t;cin>>t;
  while(t--)
    solve();
    return 0;
}