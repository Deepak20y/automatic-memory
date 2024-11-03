#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    // Calculate minimum and maximum possible sums
    ll min_sum = (k * (k + 1)) / 2; // Minimum sum of the first k integers
    ll max_sum = k * n - (k * (k - 1)) / 2; // Maximum sum of the largest k integers

    // Check if x is within the possible range
    if (x >= min_sum && x <= max_sum) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }
    return 0;
}
