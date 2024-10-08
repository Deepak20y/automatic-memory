#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;

vector<int> a;
int m;
int dp[25][12][1003];

// Helper function to print the path
void printPath(vector<int>& path) {
    for (int p : path) {
        cout << p << " ";
    }
    cout << endl;
}

int recur(int currw, int previous, int cnt, vector<int>& path) {
  //  cout << currw << " " << previous << " " << cnt << endl;
    
    if (cnt == m) {
        // Base condition when solution is found
        //printPath(path);
        return 1;
    } else if (currw > 10) return 0;

    if (dp[currw][previous][cnt] != -1) return dp[currw][previous][cnt];

    bool ok = false;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != previous && currw < a[i]) {
            path.push_back(a[i]);  // Add the current choice to the path
            ok |= recur(abs(a[i] - currw), a[i], cnt + 1, path);
            if (ok) return dp[currw][previous][cnt] = 1;  // If a solution is found, return early
            path.pop_back();  // Backtrack: remove the choice if it leads to no solution
        }
    }

    return dp[currw][previous][cnt] = ok;
}

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < 10; i++) if (s[i] == '1') a.push_back(i + 1);
    cin >> m;

    memset(dp, -1, sizeof(dp));
    vector<int> path;

    if (recur(0, 0, 0, path) == 1) {
        cout << "YES" << endl;
        printPath(path);
    } else {
        cout << "NO" << endl;
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
