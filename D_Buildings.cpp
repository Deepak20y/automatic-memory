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

    vector<int> a(n, 0);

    vector<pair<int, int>> b;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back({x, i});
    }

    sort(b.begin(), b.end(), [&](const pair<int, int> &aa, const pair<int, int> &bb)
         { return aa.first > bb.first; });

    set<int> c;
    for (auto &[x, y] : b)
    {

        if (c.size() == 0)
        {
            if (y != 0)
            {
                a[0]++;
                a[y]--;
            }
        }
        else
        {

            auto sp = c.lower_bound(y);
            if (sp == c.begin())
            {
                a[0]++;
                a[y]--;
            }
            else
            {
                sp--;
                a[*sp]++;
                a[y]--;
            }
        }

        c.insert(y);
    }

    for (int i = 0; i < n - 1; i++)
        a[i + 1] += a[i];

    for (auto &x : a)
        cout << x << " ";
    cout << endl;

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