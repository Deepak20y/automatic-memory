#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MX = 1e5 + 5;
struct DSU
{
	int p[MX];
	int maxp[MX];
	ll sum[MX];
	int color[MX];

	vector<int> elements[MX];
	map<int, map<int, int>> ele;

	void build(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			make_set(i);
		}
	}

	void make_set(int u)
	{ // O(1)
		p[u] = u;
		elements[u].push_back(u);
		maxp[u] = 1;
	}

	void assigncolor(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			sum[i] = color[i];
			ele[i][color[i]] = 1;
		}
	}

	int find(int u)
	{ // O(1)
		return p[u];
	}

	void join(int u, int v)
	{ // O(log n) amortized
		//cout << v << " "<<u<<" ";
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
				elements[u].pop_back();
				p[x] = v;
				ele[v][color[x]]++;

				if (ele[v][color[x]] == maxp[v])
				{
					
						sum[v] += color[x];
				}
				else if (ele[v][color[x]] > maxp[v])
				{
					sum[v] = color[x];
					maxp[v] = ele[v][color[x]];
				}
			}

			//cout <<v<<" "<<maxp[v] << " " << sum[v] << endl;
		}
	}
} dsu;

vector<int> cnt;
vector<int> adj[100005];
vector<pair<int, int>> a;
vector<bool> vis;
vector<ll> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dsu.build(n + 2);

	for (int i = 1; i <= n; i++)
		cin >> dsu.color[i];

	dsu.assigncolor(n);

	for (int i = 1; i < n; i++)
	{
		int p, q;
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	queue<int> q;

	q.push(1);

	vis.assign(n + 3, false);
	ans.resize(n + 3);
	cnt.assign(n + 3, 0);

	while (!q.empty())
	{
		int sp = q.front();
		q.pop();
		vis[sp] = true;

		for (auto &x : adj[sp])
		{
			if (vis[x])
				continue;
			q.push(x);
			a.push_back({x, sp}); // this will give order of traversal
		}
	}

	// for(auto &[x,y]:a)cout<<x<<" "<<y<<endl;
	// return 0;

	while (!a.empty())
	{
		cnt[a.back().first]++;
		cnt[a.back().second]++;
		if (adj[a.back().first].size() == 1)
			ans[a.back().first] = dsu.color[a.back().first];

		// cout<<a.back().second<<" "<<" "<<cnt[a.back().second]<<" "<<adj[a.back().second].size()<<" ";
		dsu.join(a.back().first, a.back().second);

		if (cnt[a.back().second] == adj[a.back().second].size() - 1)
		{
			ans[a.back().second] = dsu.sum[dsu.find(a.back().second)];
		}

		a.pop_back();
	}

	ans[1] = dsu.sum[dsu.find(1)];

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}
