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
 
 vector<int>adj[1000];
vector<bool>vis;
set<pair<int,int>>b;



const int MX = 1005;
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
	
	void join(int u, int v) { 
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
 
  void dfs(int i,int parent)
 {   vis[i]=true;
    for(auto &x:adj[i])
    {    dsu.join(i,x);
        if(x==parent)continue;
         if(vis[x])
         {
            b.insert({max(x,i),min(x,i)});
            continue;
         }
         dfs(x,i);
    }
 }



 void solve(){
  
       
       int n;cin>>n;
      dsu.build(n);
       for(int i=0;i<n-1;i++)
       {
         int p,q;cin>>p>>q;
          p--;q--;
          //cout<<p<<" "<<q<<endl;
          adj[p].push_back(q);
          adj[q].push_back(p);
       }
 
       int cnt=0;
  vis.assign(n,false);
  set<int>d;
   int prev=0;
     for(int i=0;i<n;i++)
     { if(!vis[i])
        {dfs(i,-1);cnt++;
        d.insert(i);   
        }
         
     }
    cout<<cnt-1<<endl;
   int  p=0;
   vector<pair<int,int>>c;

   for(auto &[x,y]:b)
   {
    c.push_back({x,y});
   // cout<<x<<" "<<y<<endl;
   }
  
  

  for(int i=0;i<c.size();i++)
  { 
   queue<int>q;
    for(auto &x:d)
    { 
        // cout<<x<<" "<<dsu.find(x)<<" "<<dsu.find(c[i].first)
         if(dsu.find(c[i].first)!=dsu.find(x))
         {     
            dsu.join(x,c[i].first);q.push(x);
            cout<<c[i].first+1<<" "<<c[i].second+1<<" "<<c[i].first+1<<" "<<x+1<<endl;
             p=dsu.elements[dsu.find(x)].size();
            break;
         }
         


    }
      
    while(!q.empty()){d.erase(q.front());q.pop();}
     
    
  }
   
   



return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}