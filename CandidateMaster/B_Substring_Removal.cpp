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
const int mod= 998244353;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1)
        cout << 1 << endl;
    else
    {

        if (s[0] != s[n - 1])
        {
            int cnt = 1;
            for (int i = 0; i < n; i++)
            {
                while (i + 1 < n && s[i] == s[i + 1])
                {
                    i++;
                    cnt++;
                }
                break;
            }
            cnt++;
            for (int i = n - 1; i >= 0; i--)
            {
                while (i - 1 >= 0 && s[i] == s[i - 1])
                {
                    i--;
                    cnt++;
                }
                break;
            }
            cout << cnt + 1 << endl;
        }
        else
        {
            int p =1;
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] != s[i + 1])
                {
                    p = i + 1;
                    break;
                }
            }

            int q =n-2;
            for (int i = n - 1; i >= 1; i--)
            {
                if (s[i] != s[i - 1])
                {
                    q = i - 1;
                    break;
                }
            }

           // cout << p << " " << q << endl;

            ll mp = (n - 1 - q) + 1;
            ll tp = p + 1;
            cout << (mp * tp)%mod<< endl;
        }
    }

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