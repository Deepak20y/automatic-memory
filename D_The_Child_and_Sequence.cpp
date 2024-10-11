#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct pp
{
    ll sump, maxp;
};

struct segment
{
    int sz;
    vector<pp> tree;

    void build(int n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(2 * sz, {0LL, 0LL});
    }

    pp merge(pp a, pp b)
    {
        return {a.sump + b.sump, max(a.maxp, b.maxp)};
    }

    void initial(int i, pp v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            initial(i, v, 2 * x + 1, lx, m);
        else
            initial(i, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    pp calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || l >= rx)
            return {0LL, 0LL};
        if (l <= lx && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        return merge(calc(l, r, 2 * x + 1, lx, m), calc(l, r, 2 * x + 2, m, rx));
    }

    void update(int l, int r, int x, int node, int lx, int rx) //update the nodes if certain condition are met
    {
        if (tree[node].maxp < x || r <= lx || l >= rx)
            return;  
        if (rx - lx == 1)
        {
            tree[node].sump %= x;
            tree[node].maxp %= x;
            return;
        }
        int m = (lx + rx) / 2;
        update(l, r, x, 2 * node + 1, lx, m);
        update(l, r, x, 2 * node + 2, m, rx);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    segment tee;
    tee.build(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        tee.initial(i, {m, m}, 0, 0, tee.sz);
    }

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << tee.calc(l, r, 0, 0, tee.sz).sump << endl;
        }
        else if (type == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            tee.update(l, r, x, 0, 0, tee.sz);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            k--;
            tee.initial(k, {x, x}, 0, 0, tee.sz);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
