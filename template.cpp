// #include<bits/stdc++.h>
// using namespace std;
// using ll =long long int;
// using ull=unsigned long long;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional> 
// #include <iostream>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set;


 

//  void solve(){
       


// return;
// }
// int main()
// {
// std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
// int t;
// cin>>t;
// // t=1;
// while(t--)
// solve();
// return 0;
// }


segment tree


#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

struct segment
{
    int sz;
    vector<int> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, 0);
    }

    void initial(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            initial(i, v, 2 * x + 1, lx, m);
        else
            initial(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = 1 - tree[x];
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            set(i, 2 * x + 1, lx, m);
        else
            set(i, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return 0;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        int s1 = calc(l, r, 2 * x + 1, lx, m);
        int s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int find(int k, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        int m = (rx + lx) / 2;
        int var=calc(lx,m,0,0,sz);
        if(k<var)
        {
           return find(k,lx,m);
        }
        else return find(k-var,m,rx);
       
    }
};

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    segment tee;
    tee.build(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        tee.initial(i, m, 0, 0, tee.sz);
    }
    
    for (int i = 0; i < q; i++)
    {
        int qtype;
        cin >> qtype;
        int k;
        cin >> k;
        if (qtype == 1)
            tee.set(k, 0, 0, tee.sz);
        else
            cout << tee.find(k, 0,n) << endl;
    }

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}


//dsu template


#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
const int MX = 1e5;
struct DSU{
	int p[MX];
	vector<int> elements[MX]; 
	
	void build(int n) { //O(n)
		for (int i = 0; i < n; i++) {
			make_set(i);
		}
	}
	
	void make_set(int u) {  //O(1)
		p[u] = u;
		elements[u] = {u};
	}
	
	int find(int u) { //O(1)
		return p[u];
	}
	
	void join(int u, int v) { //O(log n) amortized
		u = find(u);
		v = find(v);
		if (u != v) {
			if (elements[u].size() > elements[v].size()) {
				swap(u , v);
			}
			while (!elements[u].empty()) {
				int x = elements[u].back();
				elements[v].push_back(x);
				p[x] = v;
				elements[u].pop_back();
			}
		}
	}
}dsu;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n , m;
	cin >> n >> m;
	dsu.build(n);
	for (int i = 0; i < m; i++) {
		string op;
		cin >> op;
		int u , v;
		cin >> u >> v;
		u--;
		v--;
		if (op[0] == 'g') {
			if (dsu.find(u) == dsu.find(v)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			dsu.join(u , v);
		}
	}
	
	return 0;
}
