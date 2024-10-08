#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;
using ll = long long int;
using ull = unsigned long long;

vector<int> adj[1005];

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int p;
    cin >> p;
    return p;
}

void solve() {
    int n;
    cin >> n;

    map<int, map<int, int>> a;
    stack<pair<int, int>> q;

    for (int i = 2; i <=n; i++) {
        q.push({1, i});
    }
   
    while (!q.empty()) {
        int l = q.top().first;
        int r = q.top().second;
        q.pop();
     //  cout<<l<<" "<<r<<endl;
        int m = ask(l, r);
          // cout<<m<<endl;
        if (m == l&&a[l][r]==0) {
            adj[l].push_back(r);
            adj[r].push_back(l);
            a[l][r]++;
            a[r][l]++;
        } else {
            if (a[l][m] == 0&&l!=m) {
                q.push({m, l});
            }
            if (a[r][m] == 0&&r!=m) {
                q.push({r, m});
            }
        }
    
        
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) {
        for (auto &x : adj[i]) {
            if (x > i) {
                ans.push_back({i, x});
            }
        }
    }

    cout << "! ";
    for (auto &[x, y] : ans) {
        cout << x << " " << y << " ";
    }
    cout << endl;
    cout.flush();

  
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
