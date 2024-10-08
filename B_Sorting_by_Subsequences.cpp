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


typedef long long Long;
const int MX = 1e5+5;
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




 void solve(){
       int n;cin>>n;

       vector<int>a(n);
  map<int,int>b;
  set<int>c;
       for(int i=0;i<n;i++){cin>>a[i];c.insert(a[i]);}
   
    int cnt=0;

    for(auto &x:c)
    {

        b[x]=cnt++;
    }

   for(int i=0;i<n;i++)a[i]=b[a[i]];

   

   
     dsu.build(n);
     for(int i=0;i<n;i++)dsu.join(i,a[i]);
        cnt=0;
     for(int i=0;i<n;i++)if(dsu.elements[i].size()>0)cnt++;

     cout<<cnt<<endl;

     for(int i=0;i<n;i++)
     {
       if(dsu.elements[i].size()>0)
       {
         cout<<dsu.elements[i].size()<<" ";
         for(auto &x:dsu.elements[i])cout<<x+1<<" ";cout<<endl;
       }

     }



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}