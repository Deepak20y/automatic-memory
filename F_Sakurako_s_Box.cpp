#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
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
    string s;
    cin >> s;
    vector<vector<int>> o(n + 2, vector<int>(26, 0));
    vector<vector<int>> e(n + 2, vector<int>(26, 0));
    for (int i = 1; i <= n; i++)
    {
    for (int j = 0; j < 26; j++)
        {
            o[i][j] = o[i - 1][j]; e[i][j] = e[i - 1][j];
        }
        if (i % 2 == 1)
        {
   o[i][s[i - 1] - 'a']++;
        }
        else
        {e[i][s[i - 1] - 'a']++;
        }
    }
    if (n&2==0)
    {
        int even = 0, odd = 0;
        for (int i = 0; i < 26; i++)
        {
            even = max(even, o[n][i]);
            odd = max(odd, e[n][i]);
        }
        cout << n - (even + odd) << endl;
    }
    else
    {
        int ans =1e9;
        for (int i = 1; i <= n; i++)
        {
            vector<int> od(26, 0);
            vector<int> ev(26, 0);
         
            for (int j = 0; j < 26; j++)
            {
                od[j] += (o[i - 1][j] + (e[n][j] - e[i][j]));ev[j] += (e[i - 1][j] + (o[n][j] - o[i][j]));
            }

            int even = 0, odd = 0;
            for (int j = 0; j < 26; j++)
            {
                even = max(even, od[j]);
                odd = max(odd, ev[j]);
            }
            ans = min(ans, n - even - odd);
        }
        cout << ans <<'\n';
    }
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}