#include<bits/stdc++.h>
using namespace std;
using ll=long long int;


struct segtree {
    int sz;
    vector<long long> tree;

    void build(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tree.assign(2*sz, 0);
    }

  

    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r||rx <= l) return;
      
        if (lx >= l && rx <= r) {
            tree[x] += v;
            return;
        }

        int m = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, m);
        add(l, r, v, 2*x+2, m, rx);
    }


    ll get(int idx, int x, int lx, int rx) {
        if (rx-lx==1) {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        if (idx < m)
            return get(idx, 2*x+1, lx, m) + tree[x];
        else
            return get(idx, 2*x+2, m, rx) + tree[x];
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;

    segtree tee;
    tee.build(n);

    int cmd;
    while (m--) {
        cin >> cmd;
        if (cmd == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tee.add(l, r, v,0,0,tee.sz);
        } else {
            int i;
            cin >> i;
            cout << tee.get(i,0,0,tee.sz) << endl;
        }
    }

    return 0;
}