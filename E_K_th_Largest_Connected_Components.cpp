#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
const int MX = 2e5+10;
struct DSU{
	int p[MX];
	vector<set<int, greater<int>>> elements;
	
	void build(int n) { //O(n)
       elements.resize(n+2);
		for (int i = 0; i < n; i++) {
			make_set(i);
		}
	}
	
	void make_set(int u) {  //O(1)
		p[u] = u;
		elements[u].insert(u);
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
				int x =*elements[u].begin();
				elements[v].insert(x);
				p[x] = v;
				elements[u].erase(x);
			}
		}
	}
}dsu;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
     int n;cin>>n;
      int q;cin>>q;

      dsu.build(n+4);

      while(q--)
      {
          int type;
          cin>>type;
          
          if(type==1)
          {
             int p,q;cin>>p>>q;
              dsu.join(p,q);
          }
          else{
                int v;cin>>v;
                  int k;cin>>k;
               int p=dsu.find(v);
            
               if(dsu.elements[p].size()<k)cout<<-1<<endl;
               else{
                 
                  int sp=1;
               // cout<<k<<endl;
                  for(auto &x:dsu.elements[p])
                  { //cout<<x<<" ";
                     if(sp==k){cout<<x<<endl;break;}
                     sp++;
                  }

                 // cout<<endl;
                   
               }


          }

      }
	


	
	return 0;
}
