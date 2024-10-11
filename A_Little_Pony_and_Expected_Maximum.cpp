#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

long double binpow(long double a, long long b) {
    long double res = 1.0;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> m >> n;
    long double ans = m * 1.0;

    for (int i = 1; i < m; i++) {
      
        long double p = (static_cast<long double>(m) - static_cast<long double>(i)) / static_cast<long double>(m);
        ans -=binpow(p,n);
    }

    
    cout << fixed << setprecision(10) << ans << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
