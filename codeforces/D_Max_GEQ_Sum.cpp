#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const long long INF = 1'000'000'000'000'000'000;
const int inf = 1e9;
const long long mod = 998244353;
const int N = 200008;
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);
#define T()    \
	int tt;    \
	cin >> tt; \
	while (tt--)
#define ll long long
#define prec cout << fixed << setprecision(8);
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pipi pair<int, pair<int, int>>
#define vii vector<int>
#define F first
#define S second
#define fill(v, p) memset(v, p, sizeof(v))
// #define print(v) for(auto &z : v)cout<<z<<" ";cout<<'\n';
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define rank asdf
bool solve(vector<int> &a)
{
	int n = sz(a);
	ll i = 0, j = 0, cur = 0, mx = INT_MIN;
	bool flag = true;
	for (; j < n; j++)
	{
		if (cur <= 0)
		{
			cur = 0;
			i = j;
			mx = a[j];
		}
		cur += a[j];
		mx = max<ll>(mx, a[j]);
		if (cur > mx)
		{
			flag = false;
			break;
		}
	}

    for(int i=0;i<n-1;i++)if(a[i]>0&&a[i+1]>0)flag=false;
	return flag;
}
int32_t main()
{
	T()
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> b = a;
		reverse(all(b));
		if (solve(a) && solve(b))
		{
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
}