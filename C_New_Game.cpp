#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }

    long long ans = 0;
    vector<pair<ll, ll>> c;

    for (auto &[x, y] : b) {
        c.push_back({x,  y});
    }
    
    n = c.size();
    
    for (int i = 0; i < n; i++) {
        vector<ll> pp;
        pp.push_back(c[i].second);
        
        while (i + 1 < n && c[i].first + 1 == c[i + 1].first) {
            
            pp.push_back(c[i+1].second);
            i++;
        }
        
        
        for (int j = 0; j < pp.size() - 1; j++) {
            pp[j + 1] += pp[j];
        }

        if(pp.size()<=k)ans=max(ans,pp[pp.size()-1]);

        for (int j = k - 1; j < pp.size(); j++) {
            if (j - k >= 0) 
                ans = max(ans, pp[j] - pp[j - k]);
            else 
                ans = max(pp[j], ans);
        }
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
