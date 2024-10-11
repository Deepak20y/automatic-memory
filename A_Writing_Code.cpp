#include <cstdio>
#include <cstring>

const int N = 505;
int a[N];
int dp[2][N][N];  // We only keep two layers (2D arrays) for memory optimization

int main() {
    int n, m, b, mod;
    scanf("%d %d %d %d", &n, &m, &b, &mod);  // Read input

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Read bug increments for each step
    }

    // Initialize the dp table
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;  // There's exactly one way to start with 0 bugs and at step 0

    // Iterate over each element (step)
    for (int it = 1; it <= n; it++) {
        int i = it & 1;  // Current layer (using i & 1 to alternate layers)
        int prev = i ^ 1;  // Previous layer

        // Loop over steps and bug count
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                dp[i][j][k] = dp[prev][j][k];  // Carry over previous layer value
                if (j > 0 && k >= a[it - 1]) {
                    dp[i][j][k] += dp[i][j - 1][k - a[it - 1]];  // Add valid transition
                    if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;  // Ensure mod constraint
                }
            }
        }
    }

    // Calculate the final answer
    int ans = 0;
    for (int i = 0; i <= b; i++) {
        ans += dp[n & 1][m][i];
        if (ans >= mod) ans -= mod;
    }

    // Output the result
    printf("%d\n", ans);

    return 0;
}
