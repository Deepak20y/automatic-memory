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


vector<pair<int,int>>query[500005];
 void solve(){
       int n;cin>>n;
       int q;cin>>q;
      vector<int>a(n);

      for(int i=0;i<n;i++)cin>>a[i];
    
    segment tee;
    tee.build(n);
      
    
  for(int i=0;i<q;i++)
  {
          int l,r;cin>>l>>r;
          l--;
          query[l].push_back({r,i});

  }

  for(int i=0;i<n;i++)sort(query[i].begin(),query[i].end());

//    for(int i=0;i<=n;i++)
//    {  
//     if(query[i].size()==0)continue; 
//     cout<<i<<endl;
//      for(auto &[x,y]:query[i])std::cout<<x<<" ";cout<<endl;
//    }
 
 

    vector<int>ans(q);
    vector<int>pos(n+4,-1);

    for(int i=n-1;i>=0;i--)
    { 
        if(pos[a[i]]==-1)
        {
            pos[a[i]]=i;
              tee.initial(pos[a[i]],1,0,0,tee.sz);

        }
        else{
          tee.initial(pos[a[i]],0,0,0,tee.sz);
          pos[a[i]]=i;
          tee.initial(pos[a[i]],1,0,0,tee.sz);
        }

        for(auto &[x,y]:query[i])
        { 
            //if(y>=q){cout<<0<<endl;return;}
           ans[y]=tee.calc(i,x,0,0,tee.sz);

        }

    }

    for(auto &x:ans)cout<<x<<'\n';






return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}