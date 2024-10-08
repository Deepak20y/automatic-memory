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


struct segtree {
    int sz;
    vector<int> tree;

    void build(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tree.assign(2*sz, 0);
    }

  

    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r||rx <= l) return;
      
        if (lx >= l && rx <= r) {
            tree[x]=max(v,tree[x]);
            return;
        }

        int m = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, m);
        add(l, r, v, 2*x+2, m, rx);
    }


    int get(int idx, int x, int lx, int rx) {
        if (rx-lx==1) {
         //   cout<<tree[x]<<endl;
            return tree[x];
        }

        int m = (lx + rx) / 2;
        if (idx < m)
            return max(get(idx, 2*x+1, lx, m), tree[x]);
        else
            return max(get(idx, 2*x+2, m, rx), tree[x]);
    }
};



 void solve(){
       

 int n;cin>>n;
 segtree tee;
 tee.build(n);

 int q;cin>>q;
 while(q--)
 {
      int type;
      cin>>type;

      if(type==1)
      { 
        int l,r,v;cin>>l>>r>>v;
        tee.add(l,r,v,0,0,tee.sz);
      }
      else{
         int idx;cin>>idx;
     cout<<tee.get(idx,0,0,tee.sz)<<endl;
     //cout<<endl;
      }

 }



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}