#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;

bool sea(ll p, ll k) {
    ll st = p - (ll)sqrtl(p);
    return st >= k;
}

void solve() {
    ll k; 
    cin >> k;
    
    ll low = 1;
    ll high = UINT64_MAX - 1;
    ll mid;

    for(int i = 0; i < 70; i++) {
        mid = low + (high - low) / 2;

        if(sea(mid, k)) high = mid;
        else low = mid;
    }

    cout << low+1LL<< endl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
