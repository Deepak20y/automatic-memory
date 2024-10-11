#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

const int mod = 1e9 + 7;

long long inv(long long a, long long b)
{
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

struct sp
{
  ll num, den;
};

struct segment
{
  int sz;
  vector<sp> tree;
  void build(int n)
  {
    sz = 1;
    while (sz < n)
      sz *= 2;
    tree.assign(2 * sz + 10, {1LL, 1LL});
  }

  sp merge(sp a, sp b)
  {
    sp st;
    st.den = (a.den * b.den) % mod;
    st.num = (a.num * b.num) % mod;
    return st;
  }

  void initial(int i, sp v, int x, int lx, int rx)
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
    tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
  }

  sp calc(int l, int r, int x, int lx, int rx)
  {
    if (r <= lx || rx <= l)
      return {1LL, 1LL};
    if (l <= lx && r >= rx)
      return tree[x];
    int m = (lx + rx) / 2;
    sp s1 = calc(l, r, 2 * x + 1, lx, m);
    sp s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
  }
};

vector<vector<pair<int, int>>> c;
vector<int> pos(1e6);
void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  segment tee;
  tee.build(n);
  c.resize(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[i] = a[i];
  }
  pos.assign(1e6, -1);
  for (int i = 0; i < n - 1; i++)
  {
    a[i + 1] *= a[i];
    a[i + 1] %= mod;
  }

    
    int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--;
    c[l].push_back({r, i});
  }

  vector<ll> ans(q);

  for (int i = n - 1; i >= 0; i--)
  {
    vector<int> d;
    //  cout<<b[i]<<":"<<endl;
    for (int j = 2; j * j <= b[i]; j++)
    {
      if (b[i] % j == 0)
        d.push_back(j);
      while (b[i] % j == 0)
        b[i] /= j;
    }

    if (b[i] > 1)
      d.push_back(b[i]);

   
    ll pp1 = 1LL, pp2 = 1LL;

    for (auto &x : d)
    {
       if(pos[x]!=-1)
      {

        int mmp = pos[x];
        sp pp = tee.calc(mmp, mmp + 1, 0, 0, tee.sz);
        pp.num = (pp.num * inv(x - 1, mod)) % mod;
        pp.den = (pp.den * inv(x, mod)) % mod;

        tee.initial(mmp, pp, 0, 0, tee.sz);
      }
      pp1 *= (x - 1), pp2 *= x;

      pp1 %= mod;
      pp2 %= mod;
      pos[x] = i;
    }
    sp lp;
    lp.num = pp1;
    lp.den = pp2;
    tee.initial(i, lp, 0, 0, tee.sz);

    for (auto &[x, y] : c[i])
    {

      sp pp = tee.calc(i, x, 0, 0, tee.sz);

      ll spp = a[x - 1];
      if (i > 0)
        spp *= inv(a[i - 1], mod);
      spp %= mod;
     // ans[y] = (((sp * pp.num % mod))%mod * inv(pp.den, mod)) % mod;
       ans[y] = (((spp * pp.num % mod))%mod * inv(pp.den, mod)) % mod;

    }
  }

  for (auto &y : ans)
    cout << y<< endl;

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