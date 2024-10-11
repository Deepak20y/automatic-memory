#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

struct segtree {
    int sz;
    vector<int> tree,lazy,countones;

    void build(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tree.assign(2 * sz, 0);
        lazy.assign(2 * sz, -1);
    }

    void apply(int x, int lx, int rx) {
        if (lazy[x] !=0) {
            tree[x]^=lazy[x];

            if (rx - lx > 1) {
                lazy[2 * x + 1]^= lazy[x];
                lazy[2 * x + 2]^= lazy[x];
            }

            lazy[x] =0;
        }
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        apply(x, lx, rx);

        if (lx >= r || rx <= l) return;

        if (lx >= l && rx <= r) {
            lazy[x]^=v;
            apply(x, lx, rx);
            return;
        }

        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
    }

    int get(int idx, int x, int lx, int rx) {
        apply(x, lx, rx);

        if (rx - lx == 1) {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        if (idx < m)
            return get(idx, 2 * x + 1, lx, m)+tree[x];
        else
            return get(idx, 2 * x + 2, m, rx)+tree[x];
    }
};

void solve() {
    int n;
    cin >> n;
    segtree tee;
    tee.build(n);

    for(int i=0;i<n;i++)
    {
        int m;cin>>m;

        for(int j=0;j<=20;j++)
        {
             if((1<<j)&m)
          
        }

    }

  



    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
