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
        tree.assign(2*sz+10, 0);
    }

    void initial(int i, ll v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x]=tree[x]+v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            initial(i, v, 2 * x + 1, lx, m);
        else
            initial(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1]+tree[2 * x + 2];
    }

   

  

    ll calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return 0;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1+s2;
    }


};


vector<int>ad[200005];
vector<pair<int,int>>query[200005];
 void solve(){
        int n;cin>>n;
        int q;cin>>q;
        vector<int>a(n+5);
   
        for(int i=0;i<n;i++)
        {
             int m;cin>>m;
             a[m]=i;
        }

       // for(auto &x:pos)cout<<x<<" ";cout<<endl;

        for(int i=1;i<=n;i++)
        { 
          for(int j=i;j<=n;j+=i)
          {
              int x=a[i];
              int y=a[j];

         if(x>y)swap(x,y);
         ad[x].push_back(y);
          

          }

        } 
         
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<endl;
    //     for(auto &x:ad[i])cout<<x<<" ";
    //     cout<<endl;
    // }

        for(int i=0;i<q;i++)
        { 
            int l,r;cin>>l>>r;
            l--;
            query[l].push_back({r,i});
        }

        vector<int>ans(q);
        segment tee;
        tee.build(n+4);
        for(int i=n-1;i>=0;i--)
        { 
          for(auto x:ad[i]){tee.initial(x,1,0,0,tee.sz);}
          
           for(auto &x:query[i])ans[x.second]=tee.calc(0,x.first,0,0,tee.sz);

        }
        
        for(auto &x:ans)cout<<x<<endl;

      

      





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}