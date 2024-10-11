#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  constexpr int INF = int(1e9);

  int n, s, l;
  cin >> n >> s >> l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> mx, mn;
  vector<int> t(n, -1);// array t is the subarray where last valid index is i and what is the maxmum size we can form
  for (int i = 0; i < n; i++) {
    while (!mx.empty() && a[mx.back()] <= a[i]) {
      mx.pop_back();
    }
    while (!mn.empty() && a[mn.back()] >= a[i]) {
      mn.pop_back();
    }
    mx.push_back(i);
    mn.push_back(i);
    for (int lo = 0, hi = i - l + 2; lo < hi; ) {
      int mid = (lo + hi) / 2;
      int mx_ = a[*lower_bound(mx.begin(), mx.end(), mid)];    //this calculates if im at ith position the last index of given subarray
                                                            // then from where the earliest subarray can start
      int mn_ = a[*lower_bound(mn.begin(), mn.end(), mid)];

      
            if (mx_ - mn_ > s) {
        lo = mid + 1;
      } else {
        
        hi = mid;
        t[i] = mid;
      }
    }
  }
 //-1 indicates that there is no subarray which ends at i and valid subarry is formed
  //for(auto &x:t)cout<<x<<" ";cout<<endl;

  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  vector<int> mndp;
  for (int i = 0; i < n; i++) {
    if (i - l + 1 >= 0) {
      while (!mndp.empty() && dp[mndp.back()] >= dp[i - l + 1]) {
        //cout<<mndp.back()<<" "<<i<<" "<<i-l+1<<" "<<dp[mndp.back()]<<" "<<dp[i - l + 1]<<endl;
        mndp.pop_back();
      }
      
      mndp.push_back(i - l + 1);
      //cout<<"Push"<<" "<<i-l+1<<endl;
    }
    if (t[i] == -1) {
      continue;
    }
    dp[i + 1] = dp[*lower_bound(mndp.begin(), mndp.end(), t[i])] + 1;
  }
  int ans = (dp[n] >= INF ? -1 : dp[n]);
  cout << ans << '\n';

  return 0;
}
