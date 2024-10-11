#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

struct DSU
{
	vector<int> p;
	vector<vector<int>> elements;

	void build(int n)
	{ // O(n)
		p.resize(n + 5);
		elements.resize(n + 4);
		for (int i = 0; i < n; i++)
		{
			make_set(i);
		}
	}

	void make_set(int u)
	{ // O(1)
		p[u] = u;
		elements[u] = {u};
	}

	int find(int u)
	{ // O(1)
		return p[u];
	}

	void join(int u, int v)
	{ // O(log n) amortized
		u = find(u);
		v = find(v);
		if (u != v)
		{
			if (elements[u].size() > elements[v].size())
			{
				swap(u, v);
			}
			while (!elements[u].empty())
			{
				int x = elements[u].back();
				elements[v].push_back(x);
				p[x] = v;
				elements[u].pop_back();
			}
		}
	}
};

void solve()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	DSU dsu;
	dsu.build(n + 1);
	map<int, map<int, int>> a;

	for (int i = 0; i < m; i++)
	{
		int a1, d, k;
		cin >> a1 >> d >> k;

		a[d][a1] = max(a[d][a1],k); // why k+1 it is beacuse if not we will never know that if ap has one term or there is no AP at all
		// cout<<a[d][a1]<<endl;
	}


	for (int d = 1; d <= 10; d++)
	{
		

		for (int p = 1; p <= d; p++)
		{
			int start = -1;
			int pp = -1;
			for (int j = p; j <= n; j += d)
			{

				if (a[d][j] > 0)
				{
					if (start == -1)
						start = j;
					pp = max(pp, a[d][j]);
				}

				if (pp >=0)
				{

					dsu.join(j, start);
					pp--;
				}

				if(pp<0)start=-1;
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{

		if (dsu.elements[i].size() > 0)
			cnt++;
	}

	cout << cnt << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}