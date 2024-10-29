#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve() {
    int q;
    cin >> q;

    // Track counts for 'a' and for any other characters in s and t
    ll count_a_s = 1, count_other_s = 0;  // "a" initially in s
    ll count_a_t = 1, count_other_t = 0;  // "a" initially in t

    bool has_other_s = false, has_other_t = false; // Track if we add non-'a' characters

    while (q--) {
        int d;
        ll k;
        string x;
        cin >> d >> k >> x;

        // Count 'a' and other characters in x
        ll new_a = 0, new_other = 0;
        for (char ch : x) {
            if (ch == 'a') new_a++;
            else new_other++;
        }

        if (d == 1) {
            // Operation on string s
            count_a_s += k * new_a;
            count_other_s += k * new_other;
            if (new_other > 0) has_other_s = true;
        } else {
            // Operation on string t
            count_a_t += k * new_a;
            count_other_t += k * new_other;
            if (new_other > 0) has_other_t = true;
        }

        // Determine if s can be lexicographically smaller than t
        bool is_lex_smaller = false;

        if (has_other_t) {
            // If t has any non-'a' character, t can always be larger lexicographically
            is_lex_smaller = true;
        } else if (!has_other_s && count_a_s < count_a_t) {
            // If s has only 'a' characters and less than t's 'a' count
            is_lex_smaller = true;
        }

        cout << (is_lex_smaller ? "YES" : "NO") << endl;
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
