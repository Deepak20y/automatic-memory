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
        while (sz < n)
            sz *= 2;
        tree.assign(2 * sz + 10, (1 << 31) - 1);
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
        tree[x] = tree[2 * x + 1] & tree[2 * x + 2];
    }

    int calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return (1 << 31) - 1;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        int s1 = calc(l, r, 2 * x + 1, lx, m);
        int s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1 & s2;
    }
};

void solve()
{
    int n;
    cin >> n;

    segment tee;
    tee.build(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        tee.initial(i, m, 0, 0, tee.sz);
    }

    int q;
    cin >> q;

    //cout<<tee.calc(0,1,0,0,tee.sz)<<endl;
    while (q--)
    {
        int l, k;
        cin >> l >> k;
        l--;
        
        int high = n - 1;
        int low = l;

        int mid;
        if (tee.calc(l, l + 1, 0, 0, tee.sz) < k)
            std::cout << -1 << " ";
        else if (tee.calc(l, n, 0, 0, tee.sz) >= k)
            cout << n << " ";
        else
        {

            for (int i = 0; i < 30; i++)
            {
                if (high >= low)
                {
                    mid = (high + low) / 2;

                    if (tee.calc(l, mid + 1, 0, 0, tee.sz) >= k)
                        low = mid;
                    else
                        high = mid;
                }
            }
            cout <<mid + 1 << " ";
        }
    }
    cout << endl;

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}