#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

int minMoves(vector<int>& arr, int k) {
    int n = arr.size();
    int MAX_VAL = *max_element(arr.begin(), arr.end()) + k; // Define a reasonable range for the values
    vector<vector<int>> dp(n, vector<int>(MAX_VAL + 1, INT_MAX));

    // Initialize the DP table for the first element
    for (int j = 0; j <= MAX_VAL; ++j) {
        dp[0][j] = abs(arr[0] - j);
    }

    // Fill the DP table
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= MAX_VAL; ++j) {
            dp[i][j] = INT_MAX; // Initialize with a large number
            for (int m = max(0, j - k); m <= min(MAX_VAL, j + k); ++m) {
                dp[i][j] = min(dp[i][j], dp[i-1][m] + abs(arr[i] - j));
            }
        }
    }

    // Find the minimum cost in the last row of DP table
    int result = INT_MAX;
    for (int j = 0; j <= MAX_VAL; ++j) {
        result = min(result, dp[n-1][j]);
        cout<<dp[n-1][j]<<endl;
    }

    return result;
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 4, 5};
    int k = 2;
    int result = minMoves(arr, k);
    // Output should be 1 for this input
    cout << "Minimum number of moves: " << result << endl;
    return 0;
}
