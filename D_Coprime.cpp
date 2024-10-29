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

vector<vector<int>> ab;

void fill()
{
    ab.resize(1002);

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i + 1; j <= 1000; j++)
        {
            if (gcd(i, j) == 1)
            {
                ab[i].push_back(j);
                ab[j].push_back(i);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
        
    int ans = 0;
    vector<pair<int, int>> a(1003, {-1, -1});
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[b[i]].first == -1)
        {
            a[b[i]].first = i + 1;
            a[b[i]].second = i + 1;
        }
        else
            a[b[i]].second = i + 1;

            if(b[i]==1)
            {
                ans=max({ans,1+i+1,n+i+1});
            }
    }

  



    for (int i = 1; i <=1000; i++)
    {
        if (a[i].first == -1)
            continue;

          //cout<<i<<" "<<a[i].first<<" "<<a[i].second<<endl;

        for (auto &x : ab[i])
        {
            if (a[x].first == -1)
                continue;

            ans = max({ans, a[x].first + a[i].first, a[x].second + a[i].first, a[x].first + a[i].second, a[x].second + a[i].second});
        }
    }

           if(ans==0)cout<<-1<<endl;
           else cout<<ans<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    fill();
    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
    return 0;
}