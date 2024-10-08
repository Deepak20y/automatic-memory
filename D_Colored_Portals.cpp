#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
 vector<pair<int,int>>adj[200005];
int depth[200005], parent[20005][30];

void buildTree(int n) {
    // Read edges and construct the tree
    // Example input format: u v w (u, v are nodes, w is weight)
    int u, v, w;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graphs
    }
}

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;
    for (auto& edge : adj[node]) {
        if (edge.first != par) {
            dfs(edge.first, node, d + 1);
        }
    }
}

void precomputeLCA(int n) {
    for (int j = 1; j < 27; j++) {
        for (int i = 0; i < n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 26; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 26; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

 void solve(){
       int n;cin>>n;
        int q;cin>>q;
       set<int>a[4];
      vector<pair<int,int>>b;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
          vector<int>c;

          if(s[0]=='B')c.push_back(0);
          else if(s[0]='G')c.push_back(1);
          else if(s[0]=='R')c.push_back(2);
          else c.push_back(3);


          if(s[1]=='B')c.push_back(0);
          else if(s[1]='G')c.push_back(1);
          else if(s[1]=='R')c.push_back(2);
          else c.push_back(3);
          b.push_back({c[0],c[1]});
         
          a[c[0]].insert(i);
          a[c[1]].insert(i);
    }
    
    int count_primes(int n) {
        const int S = 10000;
    
        vector<int> primes;
        int nsqrt = sqrt(n);
        vector<char> is_prime(nsqrt + 2, true);
        for (int i = 2; i <= nsqrt; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= nsqrt; j += i)
                    is_prime[j] = false;
            }
        }
    
        int result = 0;
        vector<char> block(S);
        for (int k = 0; k * S <= n; k++) {
            fill(block.begin(), block.end(), true);
            int start = k * S;
            for (int p : primes) {
                int start_idx = (start + p - 1) / p;
                int j = max(start_idx, p) * p - start;
                for (; j < S; j += p)
                    block[j] = false;
            }
            if (k == 0)
                block[0] = block[1] = false;
            for (int i = 0; i < S && start + i <= n; i++) {
                if (block[i])
                    result++;
            }
        }
        return result;
    }
    
    for(int i=0;i<n;i++)
    {
        int m;cin>>m;
         int p=n+1;
        auto it=a[b[i].first].upper_bound(i);
        auto pt=a[b[i].second].upper_bound(i);

       
          if(it!=a[b[i].first].end())p=min(p,*it);
          if(pt!=a[b[i].second].end())p=min(p,*pt);
       
        if(p==n+1)continue;
        else 
        {
            adj[i].push_back({p,abs(i-p)});
            adj[p].push_back({i,abs(i-p)});

        }
    }
     
     


    





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}