#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int q;
    cin >> q;
    int ans = 0;

    for (int i = 0; i < n - 3; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        {
            ans++;
        }
    }

    while (q--)
    {
        int idx;
        char c;
        cin >> idx >> c;
        idx--;
        if (s[idx] == c)
        {
            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        for (int i = max(0, idx - 3); i <= min(n - 4, idx); i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                ans--;
            }
        }

        s[idx] = c;

        for (int i = max(0, idx - 3); i <= min(n - 4, idx); i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                ans++;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
