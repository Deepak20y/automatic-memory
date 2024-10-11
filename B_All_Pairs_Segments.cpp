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
    int q;
    cin >> q;
    vector<int> a(n);

    map<ll, ll> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
   

    if (n == 2)
    {
        b[1] = a[1] - a[0] + 1;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            ll p1 = i + 1;
            ll p2 = n - i;
            //cout<<p1<<" "<<p2<<endl;
            b[p1 * p2-1]++;

            if (i + 1 < n)
            {
                int p = a[i + 1] - a[i] - 1;
                p1=i+1;
                p2=n-i-1;
                p = max(p, 0);
                if (p > 0)
                {  
                    b[p1 * p2] += p;
                }
            }
        }
    }

    //for(auto &[x,y]:b)cout<<x<<" "<<y<<endl;

    while (q--)
    {

        ll k;
        cin >> k;
        cout <<b[k]<<" ";
    }
    cout << endl;

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