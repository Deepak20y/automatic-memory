#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> digits;
ll dp[22][11][2][2]; // DP table

// Digit DP function
ll digit_dp(int pos, int last_digit, bool leading_zero, bool tight)
{
    // Base case: If all positions are filled, return 1 (we found a valid number)
    if (pos == digits.size())
    {
        return 1;
    }

    // Memoization: If already calculated, return the stored result
    if (dp[pos][last_digit][leading_zero][tight] != -1)
    {
        return dp[pos][last_digit][leading_zero][tight];
    }

    ll res = 0;
    int limit = tight ? digits[pos] : 9; // If tight, restrict the current digit

    for (int digit = 0; digit <= limit; digit++)
    {
        // If leading zero is true, we can pick any digit; otherwise, no two consecutive digits should be the same
        if (leading_zero || digit != last_digit)
        {
            res += digit_dp(
                pos + 1,
                digit,
                leading_zero && digit == 0, // Continue leading zeros if we picked 0
                tight && (digit == limit)   // Update tight if we're still bound by the original number
            );
        }
    }

    return dp[pos][last_digit][leading_zero][tight] = res;
}

// Helper function to compute valid numbers up to x
ll count_valid_numbers(ll x)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1; // Special case for 0

    // Extract digits of x
    digits.clear();
    while (x > 0)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end()); // We process the number from most significant digit

    // Initialize DP table with -1 (uncomputed states)
    memset(dp, -1, sizeof(dp));

    // Start recursion from the first digit (pos = 0), with no last digit (-1), leading_zero = true, and tight = true
    return digit_dp(0, 10, true, true);
}

// Main solve function
void solve()
{
    ll a, b;
    cin >> a >> b;

    // ans[b] - ans[a-1]: Counts numbers from a to b with the desired property
    ll result = count_valid_numbers(b) - count_valid_numbers(a - 1);

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
