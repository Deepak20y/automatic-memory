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

    vector<pair<int, int>> a;
    set<pair<int, int>> b, e;

    vector<int> c(n), f(n);
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        // cout<<m<<" ";
        a.push_back({m, i});
        e.insert({m, i});
        f[i] = m;
    }

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        // cout<<m<<" ";
        b.insert({m, i});
        c[i] = m;
    }

    sort(a.begin(), a.end());

    set<int> d;
    int p = c[a[0].second];
    int qp = f[a[0].second];
    for (int i = 0; i < n; i++)
    {
      p = max(c[a[i].second],p);
      qp =max(f[a[i].second],qp);
        bool ok = true;
          
        while (ok)
        {
            ok = false;

            auto sp = b.begin();

            while (sp != b.end())
            {
                if (sp->first <= p)
                {
                    ok = true;
                    d.insert(sp->second);
                    qp = max(qp, f[sp->second]);
                    b.erase(sp);
                    sp = b.begin();
                }
                else
                    break;
            }

            auto mp = e.begin();

            while (mp != e.end())
            {
                if (mp->first <= qp)
                {
                    ok = true;
                    d.insert(mp->second);
                    p = max(p, c[mp->second]);
                    e.erase(mp);
                    mp = e.begin();
                }
                else
                    break;
            }
        }

      //  cout<<qp<<" "<<p<<endl;
        d.insert(a[i].second);
        if (d.size() != n)
            ans[a[i].second] = 0;
        else
            break;
    }

    for (auto &x : ans)
        cout << x;
    cout << "\n";

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
    return 0;
}