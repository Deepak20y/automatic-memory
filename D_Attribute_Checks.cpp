#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

// Defining an ordered multiset type using pb_ds
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

int dp[5005][5005];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp)); // Initialize dp array to 0
    ordered_multiset a; // For positive values
    ordered_multiset b; // For negative values
    int point = 0;
    int prev = -1;

    int ans = 0;
    
   

    for (int i = 0; i < n + 1; i++) {
        int p;
        if (i != n)
            cin >> p;
        else
            p = 0; // End signal

        if (p == 0) {
            // Update dp table using ordered multisets a and b
            if (point == 0) {
                point++;
                a.clear();
                b.clear();
                continue;
            }

            // Use proper indices for l and r
          

              for(int j=0;j<=point;j++)
              {
                 dp[point][j]=max(dp[point][j])

              }

            // Clear the multisets and increment the point
            a.clear();
            b.clear();
            point++;
        } else {
            prev = 0;
            if (p > 0) {
                a.insert(abs(p)); // Insert into the positive multiset
            } else {
                b.insert(abs(p)); // Insert into the negative multiset
            }
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
