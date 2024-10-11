#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

int mod = 1e9+7;

// Function to calculate the number of segments to flip from 'a' to 'b'
int cal(const string &a, const string &b) {
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (a[i] == '0' && b[i] == '1') cnt++;
        if (a[i] == '1' && b[i] == '0') return INT_MAX; // Invalid flip
    }
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<string> check = {
        "1110111", "0010010", "1011101", "1011011", "0111010", 
        "1101011", "1101111", "1010010", "1111111", "1111011"
    };

    // Precompute the number of flips required for each segment to match each digit
    int dp[n + 1][10]; // Store flip costs for each digit
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = cal(arr[i], check[j]);
        }
    }

    // Store the maximum number as string for each possible operation count
    vector<string> mx(k + 1, "");
    
    // Traverse through each segment and calculate the best number we can form
    for (int i = 1; i <= n; i++) {
        auto temp = mx; // Temporary storage for updates
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= 9; l++) {
                if (j - dp[i][l] >= 0 && ((i != 1 && mx[j - dp[i][l]].length() == i - 1) || (i == 1 && j - dp[i][l] == 0))) {
                    char now = '0' + l;
                    string check = mx[j - dp[i][l]] + now;
                    if (check.size() > temp[j].size()) {
                        temp[j] = check;
                     } else {
                        // temp[j] = max(temp[j], check);
                        if(std::lexicographical_compare(temp[j].begin(), temp[j].end(), check.begin(), check.end()))temp[j]=check;
                    }
                }
            }
        }
        mx = temp; // Update mx with new best values
    }

    // If we can't form a valid number of length n with k flips, output -1
    if (mx[k].length() < n) {
        cout << -1 << endl;
    } else {
        cout << mx[k] << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
