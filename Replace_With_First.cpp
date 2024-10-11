#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s[0] != t[0])
    {
        cout << -1 << endl;
        return;
    }
    
    int p = -1;
    for (int i = 0; i < min(n, m); i++)
        if (s[i] != t[i])
        {
            p = i;
            break;
        }
    
    if(n==m&&p==-1)cout<<0<<endl;
    else if (p == -1)
        cout << 1 << endl;
    else
    {
        cout << 2 << endl;
    }

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