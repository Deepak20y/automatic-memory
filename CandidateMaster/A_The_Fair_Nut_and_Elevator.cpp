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
    vector<int> a(n + 1);
   
    for (int i = 1; i <= n; i++)
        cin >> a[i];

        int ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            int minp = 0;
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                    minp += 4*a[j] *(j-1);
                else
                    minp += 4 * (i-1)* a[j];

                   // cout<<minp<<" ";
            }
             //cout<<endl;
             ans = min(ans, minp);
        }
            
       


    cout << ans << endl;

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