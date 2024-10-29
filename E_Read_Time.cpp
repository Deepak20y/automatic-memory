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
vector<ll> a, b;
vector<bool> vis;
int n, m;
bool sea(ll mid)
{
    vis.assign(m, false);

    int j = 0;
    ll time = 0LL; // it is the number of tracks it goes in left
    ll pt = 0LL;   // It is number of rows it goes in the right after going to left
    for (int i = 0; i < m && j < n; i++)
    {

        if (b[i] - a[j] <= 0 && abs(b[i] - a[j])<=mid)
        {
            time = max(abs(b[i] - a[j]), time);
            vis[i] = true;
            //cout<<mid<<" "<<i<<endl;
        }
        else
        {
            ll mt = b[i] - a[j];

            ll tp = min(2 * mt + time, 2 * time + mt);
            
            if (tp <= mid&&tp>=0)
            {
                vis[i] = true;
                //cout<<tp<<" "<<mid<<" "<<i<<endl;
            }
            else
            {
                time = 0LL;
                j++;
                i--;
            }
        }
    }
      //for(auto x:vis)cout<<x<<" ";cout<<endl;
    for (int i = 0; i < m; i++)
    {
        if (vis[i] == false)
            return false;
    }

    return true;
}
void solve()
{ 
    cin >> n;
    cin >> m;
    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    ll low = 0;
    ll high = 1e11;
    ll mid;

    for (int i = 0; i < 50; i++)
    {
        if (high >= low)
        {
            mid = (high + low) / 2LL;
            if (sea(mid))
                high = mid;
            else
                low = mid;
        }
    }
    
    cout<<high<<endl;
   // cout <<sea(high) << endl;
    

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