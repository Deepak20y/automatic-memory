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

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> b[i];

    a[0] = b[0];
    ll sum = a[0];
    ll maxp = a[0];
    
    for (int i = 1; i < n; ++i)
    {
        ll now = (b[i] - sum);
        if(now>0){
            // sum+=now;
            maxp+=now;
            sum+=maxp;
        }else{
            now = b[i] + maxp - sum;
            sum+=now;
        }
    }
    maxp = maxp+69;
    a[0] = maxp;
    sum = maxp;
    for(int i=1;i<n;i++){
        ll curr = b[i] + maxp - sum;
        a[i] = curr;
        sum+=curr;
    }
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
    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
    return 0;
}