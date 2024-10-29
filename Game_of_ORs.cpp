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
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
  
    vector<int> last;
    ll curr = a[n - 1];

    a.pop_back();
    vector<ll> ans;
    ans.push_back(curr);
    ll total = curr;

    while (!a.empty())
    {
        n = a.size();

        //for(auto &x:a)cout<<x<<" ";cout<<endl;

        vector<bool> b(n, true);
        int maxp = -1;
        ll ansp = 0;

      

        for (int i = 0; i < n; i++)
        { // cout<<(curr|a[i])<<" "<<a[i]<<endl;
            if ((curr | a[i]) > ansp)
            {
                ansp = curr | a[i];
                maxp = a[i];
            }
        }
  
        curr = ansp;
          // cout<<maxp<<" "<<curr<<endl;
        ans.push_back(maxp);

        for (int i = 0; i < n; i++)
        {

            if (maxp == a[i])
            {
                maxp = -1;
                b[i] = false;
            }
            else if ((curr | a[i]) == curr)
            {  //cout<<curr<<" "<<a[i]<<endl;
                b[i] = false;
                last.push_back(a[i]);
            }
        }
        total += curr;
        vector<int> remain;

        for (int i = 0; i < n; i++)
        {
            if (b[i])
                remain.push_back(a[i]);
        }

        a.clear();
        n = remain.size();
        if (n == 0)
            break;
        else
        {

            for (auto &x : remain)
                a.push_back(x);
        }
    }

    for (auto &x : last)
    {
        total += curr;
        ans.push_back(x);
    }

   
    n = ans.size();
    for (int i =0; i<n; i++)
        cout << ans[i] << " ";
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