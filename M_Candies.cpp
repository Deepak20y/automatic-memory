#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);  // 1-based index
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= k; i++) {
        dp[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        vector<int> sums(k + 1, 0);
        sums[0] = dp[i - 1][0];
        for (int j = 1; j <= k; j++) {
            sums[j] = (sums[j - 1] + dp[i - 1][j]) % MOD;
        }
        
        for (int j = 0; j <= k; j++) {
            int tr = sums[j]; 
            int unreachable = j - a[i] - 1;  
            
            if (unreachable >= 0) {
                tr = (tr - sums[unreachable] + MOD) % MOD; 
            }
            
            dp[i][j] = tr;
        }
    }
    
    cout << dp[n][k] << endl;
    
    return 0;
}
