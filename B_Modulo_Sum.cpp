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

void solve()
{
  int n;
  cin >> n;
  int m;
  cin >> m;

  map<int, int> b;
  for (int i = 0; i < n; i++)
  {
    int p;
    cin >> p;
    p %= m;
    b[p]++;

    if (b[p] >= m)
    {
      cout << "YES" << endl;
      return;
    }
  }

  vector<int> dp(m + 3, 0);
  set<int> a;

  for (int i = 0; i < m; i++)
    a.insert(i);

  if (b[0] > 0)
  {
    cout << "YES" << endl;
    return;
  }

  for (auto &[x, y] : b)
  {

    if (x == 0)
      continue;
    queue<int> qq;

    for (int i = x; i <= x * y; i += x)
    {
      int p = i % m;

      if (a.find(p) != a.end())
        qq.push(p);

      for (auto &y : a)
      {
        int p = ((y - i) % m + m) % m;

        if (a.find(p) == a.end())
        {
          qq.push(y);
        }
      }
    }

    while (!qq.empty())
    {
      dp[qq.front()] = 1;

      if (a.find(qq.front()) != a.end())
        a.erase(qq.front());
      qq.pop();
    }

    if (dp[0])
    {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
  return;

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