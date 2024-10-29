#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int ulx, uly, lrx, lry;
    cin >> ulx >> uly >> lrx >> lry;
    
   long  double dx, dy;
    cin >> dx >> dy;

    int n;
    cin >> n;

    // Maximum possible radius
    int MAXr = min({abs(ulx - dx), abs(lrx - dx), abs(uly - dy), abs(lry - dy)});

    // Array to track invalid radii
    vector<int> invalidR(12005, 0);

   long double eps = 1e-7;  // Small tolerance for floating-point precision issues

    for (int i = 0; i < n; i++) {
      long  double x1, y1, r1;
        cin >> x1 >> y1 >> r1;

        // Distance between the tree center (x1, y1) and the device (dx, dy)
       long double d = sqrt((x1 - dx) * (x1 - dx) + (y1 - dy) * (y1 - dy));
        
        // Calculate the range of invalid radii
        int minR = ceil(d - r1 - eps);  // First radius that touches or intersects the tree
        int maxR = floor(d + r1 + eps); // Last radius that touches or intersects the tree
        minR++;
        maxR--;
        if (minR <= maxR && minR <= MAXr) {
            maxR = min(maxR, MAXr);
            minR = max(minR, 0);
            invalidR[minR]++;
            invalidR[maxR + 1]--;
        }
    }

    // Count valid radii
    int cnt = 0;
    int currentInvalid = 0;
    for (int r = 1; r <= MAXr; r++) {
        currentInvalid += invalidR[r];
        if (currentInvalid == 0) {
            cnt++;  // This radius is valid
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
