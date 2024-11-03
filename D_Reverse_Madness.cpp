#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> l(k), r(k);
    for (int i = 0; i < k; i++) {
        cin >> l[i];
        l[i]--; // Convert to 0-based indexing
    }
    for (int i = 0; i < k; i++) {
        cin >> r[i];
        r[i]--; // Convert to 0-based indexing
    }

    int q;
    cin >> q;

    vector<int> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i];
        query[i]--; // Convert to 0-based indexing
    }

    // Step 1: Track reversal operations for each segment directly
    vector<int> reversalCount(k, 0);
    for (int i = 0; i < q; i++) {
        int pos = query[i];
        
        // Identify the segment index for the given position
        int segIdx = 0;
        while (!(l[segIdx] <= pos && pos <= r[segIdx])) {
            segIdx++;
        }

        // Calculate `a` and `b` for the reversal
        int a = min(pos, r[segIdx] + l[segIdx] - pos);
        int b = max(pos, r[segIdx] + l[segIdx] - pos);
        
        // Mark this segment for a reversal
        reversalCount[segIdx] ^= 1; // XOR to toggle the reversal for this segment
    }

    // Step 2: Apply the reversals based on the count
    for (int i = 0; i < k; i++) {
        if (reversalCount[i] % 2 == 1) {
            // If the segment was reversed an odd number of times, apply the reversal
            reverse(s.begin() + l[i], s.begin() + r[i] + 1);
        }
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
