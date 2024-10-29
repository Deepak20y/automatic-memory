#include <bits/stdc++.h>
using namespace std;

const short N = 5001;
short a[N], start[N], en[N]; // a is the initial list of numbers, start and en our the first and last occurrences of a certain number.
long dp[N];
bool s[N];

int main() {
  short n;
  cin >> n;
  for (short i = 0; i < n; ++i) {
	cin >> a[i];
	en[a[i]] = i;
  }
  for (short i = n-1; i >= 0; --i)
	start[a[i]] = i;

  dp[0] = 0;
  for (short i = 0; i < n; ++i) {
	if (en[a[i]] != i)
	  dp[i+1] = dp[i];
	else {
	  // s[N] keeps track of which numbers we have encountered or not
	  for (short k = 0; k < N; ++k) s[k] = false;
	  short mi = start[a[i]]; // predicted start of our segment
	  bool valid = true;
	  for (short j = i; valid and j >= mi; --j) {
		if (en[a[j]] > en[a[i]])
		  valid = false;
		s[a[j]] = true;
		mi = min(mi, start[a[j]]);
	  }
	  if (valid) {
		long acc = 0;
		for (short k = 0; k < N; ++k)
		  if (s[k])
			acc ^= k;
		dp[i+1] = max(dp[i], dp[mi] + acc);
	  }
	  else
		dp[i+1] = dp[i];
	}
  }

  cout << dp[n] << endl;
}