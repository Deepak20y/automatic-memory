#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n, k;
    cin >> n >> k;
    set<int> b;
    vector<int> a(n);
    vector<int> c[55];
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        a[i] = m;
        c[m].push_back(i);
    }
    if (k == 2)
    {
        sort(a.begin(), a.end());
        cout << a[n - 1] + a[n - 2] << endl;
        return;
    }

    k -= 2;
    for (int i = 50; i >= 1; i--)
    {
        while (!c[i].empty() && k > 0)
        {
            b.insert(c[i].back());
            c[i].pop_back();
            k--;
        }
    }
   
 vector<int> dd;
 
     int mp = *b.begin();
    auto st = b.end();
    st--;
    int qp = *st;
  
    vector<pair<int, int>> d;
    for (int i = mp - 1; i >= 0; i--)
    {
        d.push_back({a[i], i});
    }
     
    

    sort(d.begin(), d.end());
    int sp = 2;
    
    for(int i=d.size()-1;i>=0&&sp>0;i--)
    {
        dd.push_back(d[i].second);
        sp--;
    }

    d.clear();

    for (int i = qp + 1; i < n; i++)
    {
        d.push_back({a[i], i});
    }

    sort(d.begin(), d.end());
    sp = 2;
    for(int i=d.size()-1;i>=0&&sp>0;i--)
    {
        dd.push_back(d[i].second);
        sp--;
    }

    d.clear();
 
    for (int i = mp + 1; i < qp&&sp>0; i++)
    {
        if (b.find(a[i]) != b.end())
            continue;
        d.push_back({a[i], i});
    }

    sort(d.begin(), d.end());

    sp = 2;
    for(int i=d.size()-1;i>=0&&sp>0;i--)
    {
        dd.push_back(d[i].second);
        sp--;
    }

   // for(auto &x:dd)cout<<x<<" ";cout<<endl;

    int sum = 0;
    int ans = 0;

    for (auto &x : b)
    {
        sum += 2LL * a[x];
    }

    sum -= 2*a[mp];
    if(mp!=qp)sum-=2*a[qp];
 // cout<<sum<<endl;
 
    for (int i = 0; i < dd.size(); i++)
    {
        for (int j = i + 1; j < dd.size(); j++)
        {

            vector<int> e;
            if(mp!=qp)
            {e.push_back(mp);
            e.push_back(qp);
            e.push_back(dd[i]);
            e.push_back(dd[j]);
            
            sort(e.begin(), e.end());
            //for(auto &x:e)cout<<x<<" ";cout<<endl;
            ans = max(ans,sum+ a[e[0]] + 2 * a[e[1]] + 2 * a[e[2]] + a[e[3]]);}
            else{
                
                e.push_back(mp);
            e.push_back(dd[i]);
            e.push_back(dd[j]);
            sort(e.begin(), e.end());
            ans = max(ans,sum+ a[e[0]] + 2 * a[e[1]] +a[e[2]]);

            }
        }
    }

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
    while (t--)
        solve();
    return 0;
}