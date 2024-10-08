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
    int x, k;
    cin >> x >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    vector<int> b;
    
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (i + 1 < n && a[i] == a[i + 1])
        {
            i++;
            cnt++;
        }
        if(cnt>=2)cnt=2;
        if(x<=a[i])cnt=1;
        while (cnt--)
            b.push_back(a[i]);
           
    }

    //for(auto &x:b)cout<<x<<" ";cout<<endl;return;

    n = b.size();
    int ans = 0;
    
     int scnt=0;
     int ox=x*k;
     int unique=0;
     vector<int>sp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] < ox)
        {
            scnt++;
            ox = b[i];
            unique++;
        }
        
    }
  
    ans = max(ans, scnt);
    
    
    for (int i = 0; i < n; i++)
    {
        if (x <= b[i])
            break;
        int cnt = 1;
        while (i + 1 < n && b[i] == b[i + 1])
        {
            cnt++;
            i++;
        }

        int up = upper_bound(b.begin(), b.end(), b[i] * k) - b.begin();

        if (up == n)
            up--;
        // cout<<up<<endl;
        while (b[up] >= b[i] * k)
            up--;
        int sp = 0;
        if (cnt == 1)
            sp = i;
        else
            sp = i - 1;
         //cout<<unique<<" "<<" "<<up<<" "<<sp<<" "<<up-sp+1<<endl;
        ans = max(ans,up - sp + 1);
    
        
    }

   // ans = max(ans, unique);
    
   
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