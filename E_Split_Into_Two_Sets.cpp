#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


map<int, vector<int>> m;
vector<bool> used;

int go(int v) {
    used[v] = true;
    for (auto now : m[v]) {
        if (!used[now]) {
            return go(now) + 1; //return cycle length
        }
    }
    return 1;
}

void solve() {

    int n, x, y;
    cin >> n;

    m.clear();
    used.clear();
    used.resize(n + 1, false);

    bool fault = false;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        m[x].push_back(y);
        m[y].push_back(x);
        if (x == y || m[x].size() > 2 || m[y].size() > 2) fault = true;
    }

    if (fault) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<n;i++) {
        if (!used[i + 1]) {
            if (go(i + 1) % 2) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}
int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        solve();
    }
}