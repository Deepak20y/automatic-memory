#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

vector<int> a;
int n, k;

bool sea(int p) {
     bool ok=true;
    int cnt = 0;
    int sp = 0;
    for (int i = 0; i < n; i++) {
        if (sp == 0 && a[i] <= p) {
            cnt++;
            sp = 1;
        } else if (sp == 1) {
            cnt++;
            sp = 0;
        }
        if(cnt==k)break;
    }
    if (cnt==k)ok=false;;

    cnt = 0;
    sp =0;
    for (int i = 0; i < n; i++) {
        if (sp == 0) {
            cnt++;
            sp = 1;
        } else if (sp == 1 && a[i] <= p) {
            cnt++;
            sp = 0;
        }
        if(cnt==k)ok=false;
    }
    return ok;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int low = 0;
    int high = 1e9 + 4;
    int mid;
    int ans = high;

    for (int i = 0; i <70; i++) {  
        if (low <= high) {
            mid = (low + high) / 2;
            if (sea(mid)) {
                low= mid;
            } else {
                high = mid;
            }
        }
    }
  cout<<low+1<<" ";
   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
