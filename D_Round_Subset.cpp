#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

int dp[2][202][6005]; // Reduced size to 2 instead of 3 as only two layers are needed

void solve() {
    int n;
    cin >> n;
    int sk;
    cin >> sk;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);

    int sp = 0;

    for (int i = 1; i <= n; i++) {
        ll m;
        cin >> m;
        while (m % 2LL == 0) {
            a[i]++;
            m /= 2LL;
        }
        while (m % 5LL == 0) {
            b[i]++;
            m /= 5LL;
            sp++;
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0; // Initialize with zero for the base case

    int neww = 0, curr = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sk; j++) {
            for (int k = 0; k <= sp; k++) {
                dp[curr][j][k] = dp[neww][j][k]; // Carry forward the previous state
                if (j > 0 && k >= b[i] && dp[neww][j - 1][k - b[i]] != -1) {
                    dp[curr][j][k] = max(dp[curr][j][k], dp[neww][j - 1][k - b[i]] + a[i]);
                }
            }
        }
        swap(neww, curr);
    }

    int ans = 0;

    for (int i = 0; i <= sp; i++) {
        if (dp[neww][sk][i] != -1) {
            ans = max(ans, min(i, dp[neww][sk][i]));
        }
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
