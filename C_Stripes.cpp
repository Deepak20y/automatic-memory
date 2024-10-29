#include <bits/stdc++.h>
using namespace std;

void solve() {
    char a[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> a[i][j];

    // Check each row for a full 'R' stripe
    for (int i = 0; i < 8; i++) {
        bool allRed = true;
        for (int j = 0; j < 8; j++) {
            if (a[i][j] != 'R') {
                allRed = false;
                break;
            }
        }
        if (allRed) {
            cout << "R" << endl;
            return;
        }
    }

    // Check each column for a full 'B' stripe if no full 'R' stripe was found
    for (int j = 0; j < 8; j++) {
        bool allBlue = true;
        for (int i = 0; i < 8; i++) {
            if (a[i][j] != 'B') {
                allBlue = false;
                break;
            }
        }
        if (allBlue) {
            cout << "B" << endl;
            return;
        }
    }
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
