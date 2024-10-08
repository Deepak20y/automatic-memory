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
        tree[x] =tree[2 * x + 1] +tree[2 * x + 2];
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
        return s1+s2;
    }

};
 unordered_map<int,int>c;

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
   b.push_back(0);
      b.push_back(1e9+7);

    sort(b.begin(),b.end());
     map<int,int>c;
     int cnt=0;

     
    for(int i=0;i<b.size();i++)
    { 
        c[b[i]]=cnt++;
    }

     segment tee1,tee2;
   
     tee1.build(cnt);
     tee2.build(cnt);
    
     for(int i=1;i<n;i++)
     {
         tee2.initial(c[a[i]],1,0,0,tee2.sz);
     }

    // for(auto &[x,y]:c)cout<<x<<" "<<y<<endl;

ll ans=0LL;
    tee1.initial(c[a[0]],1,0,0,tee1.sz);
    for(int i=1;i<n-1;i++)
    { 
        

       ll p=tee1.calc(c[a[i]]+1,cnt,0,0,tee1.sz);

       ll st=tee2.calc(0,c[a[i]],0,0,tee2.sz);

        tee1.initial(c[a[i]],1,0,0,tee1.sz);
        tee2.initial(c[a[i]],0,0,0,tee2.sz);

     //   cout<<i<<" "<<p<<" "<<st<<endl;
        
        ans+=p*st;
       
    }
    cout<<ans<<endl;
    
 
 
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