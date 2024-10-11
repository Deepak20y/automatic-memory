#include <cstdio>
#include <cstring>

int MOD;
int dp[505][505];        // dp[i][bug] represents the number of ways at step i with bug count
int sum_dp[505][505];    // sum_dp[i][bug] is the cumulative sum of dp[i][j][bug]
int a[505];              // Array a which stores the values

void solve() {
    int n, m, b;
    
    // Input: n is the number of steps, m is the max steps, b is the bug limit
    // Array a stores the number of bugs added at each step
    scanf("%d %d %d", &n, &m, &b);
     scanf("%d",&MOD);
    
    // Input the bug values for each step
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize dp and sum_dp arrays to zero
    memset(dp, 0, sizeof(dp)); 
    memset(sum_dp, 0, sizeof(sum_dp));

    // Base case: there's exactly one way to be at step 0 with 0 bugs
    dp[0][0] = 1;

    // Fill DP table
    for (int i = 0; i < m; i++) {  // Loop over each step i

        // Calculate cumulative sum for current step i
        for (int bug = 0; bug <= b; bug++) {   // For each bug count
            sum_dp[i][bug] = dp[i][bug];       // Initialize sum_dp with dp[i][bug]
            if (bug > 0) {
                sum_dp[i][bug] += sum_dp[i][bug - 1];  // Cumulative sum of bugs up to this point
                sum_dp[i][bug] %= MOD;
            }
        }

        // Transition to the next step
        for (int j = 1; j <= n; j++) {  // For each possible starting position (step j)
            for (int bug = 0; bug <= b; bug++) {  // For each possible bug count
                int new_bug = bug + a[j];  // Calculate new bug count after adding from array a
                if (new_bug <= b) {  // Only proceed if the new bug count doesn't exceed the limit
                    dp[i + 1][new_bug] += sum_dp[i][bug];  // Add all possible ways up to this bug
                    dp[i + 1][new_bug] %= MOD;  // Ensure the result stays within the mod limit
                }
            }
        }
    }

    // Calculate the result by summing up all valid states at the last step (i == m)
    int ans = 0;
    for (int bug = 0; bug <= b; bug++) {
        ans += dp[m][bug];
        ans %= MOD;
    }

    // Output the result
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
