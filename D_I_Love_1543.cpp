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
    char a[n + 5][m + 5];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }

    int ans = 0;

    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {
        string s = "";
        for (int i = left; i <= right; i++)
        {
            s.push_back(a[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            s.push_back(a[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                s.push_back(a[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                s.push_back(a[i][left]);
            }
            left++;
        }

        s.push_back(s[0]);
        s.push_back(s[1]);
        s.push_back(s[2]);

        for (int i = 0; i < s.size() - 3; i++)
        {
            if (s[i] == '1' && s[i + 1] == '5' && s[i + 2] == '4' && s[i + 3] == '3')
                ans++;
        }
    }

    cout << ans << endl;

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