#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    if (n == 1) {
        cout << "Just a legend" << endl;
        return;
    }

    // Step 1: Calculate the LPS (longest prefix which is also a suffix)
    vector<int> lps1(n, 0);
    int len = 0;
    int i = 1;
    
    // Compute the LPS array
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps1[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps1[len - 1];
            } else {
                lps1[i] = 0;
                i++;
            }
        }
    }

    // Step 2: Get the length of the longest prefix-suffix for the full string
    int lps_value = lps1[n - 1]; // The last value in LPS array
    int mx = 0; // Maximum prefix-suffix that appears in the middle
    
    // Step 3: Find the maximum value of LPS that appears before the last character
    for (int i = 0; i < n - 1; i++) {
        mx = max(mx, lps1[i]);
    }

    // Step 4: Check if the LPS of the full string can be found in the middle
    if (lps_value == 0 || (lps_value > mx && lps1[lps_value - 1] == 0)) {
        cout << "Just a legend" << endl;
    } else {
        // If valid, print the prefix which is also a suffix
        int len_to_print = (lps_value <= mx) ? lps_value : lps1[lps_value - 1];
        cout << s.substr(0, len_to_print) << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
