#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
const int mod = 1e9 + 7;
struct segment
{
    int sz;
    vector<ll> tree;
    void build(int n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(2 * sz + 10, 0LL);
    }

    void initial(int i, ll v, int x, int lx, int rx)
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
        tree[x] = (tree[2 * x + 1] + tree[2 * x + 2]) % mod;
    }

    ll calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return 0LL;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m, rx);
        return (s1 + s2) % mod;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    segment tee;
    tee.build(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second=i;
    }
  

    sort(a.begin(), a.end());
      //for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;


    for (int i = 0; i < n; i++)
    {
        vector<pair<int, ll>>b;
        b.push_back({a[i].second, 1});
        while (i + 1 < n && a[i].first == a[i + 1].first)
        {
            b.push_back({a[i+1].second, 1});
            i++;
        }

        for (int j = 0; j < b.size(); j++)
        {

            b[j].second += tee.calc(0, b[j].first, 0, 0, tee.sz);
        }

        for (int j = 0; j < b.size(); j++)
        {

            tee.initial(b[j].first, b[j].second, 0, 0, tee.sz);
        }
    }

    ll ans = 0LL;

    for (int i = 0; i < n; i++)
    {
        ans += tee.calc(i, i + 1, 0, 0, tee.sz);
        ans %= mod;
    }

    cout << ans;

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