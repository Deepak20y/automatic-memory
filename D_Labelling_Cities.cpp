#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
vector<vector<int>> adj;
vector<int> ans;

vector<bool> vis;

void solve()
{
    int n;
    cin >> n;
    adj.resize(n + 4);
vector<int> adjj[n+3][3];
    int m;
    cin >> m;
    map<int, map<int, int>> present;
   
    for (int i = 0; i < m; i++)
    {

        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
        present[l][r]++;
        present[r][l]++;

        
    }

    vis.assign(n + 2, false);

    queue<int> q;
    q.push(1);

    ans.assign(n + 3, -1e9);
    ans[1]=0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
       
        if(vis[p])continue;
        vis[p] = true;
        
        for (auto &x : adj[p])
        {
            if (vis[x]||ans[x]!=-1e9)
                continue;

            q.push(x);

           
            if (adjj[p][1].empty())
            {
                adjj[p][1].push_back(x);
                adjj[x][1].push_back(p);
               
                
                ans[x] = ans[p] + 1;
               //  cerr<<1<<" "<<x<<" "<<p<<" "<<ans[p]<<" "<<ans[x]<<endl;
                continue;
            }
            else
            {

                bool ok = true;
                for (auto &y : adjj[p][1])
                {  
                    if (present[x][y] == 0)
                    {  //cout<<x<<" "<<y<<" "<<present[x][y]<<endl;
    
                        ok = false;
                        
                        break;
                    }
                }

                if (ok)
                {    
                    adjj[p][1].push_back(x);
                    adjj[x][1].push_back(p);
                 
                    ans[x] = ans[p] + 1;
                  //  cerr<<2<<" "<<x<<" "<<p<<" "<<ans[p]<<" "<<ans[x]<<endl;
                    continue;
                }
            }

            if (adjj[p][2].empty())
            {   
                adjj[p][2].push_back(x);
                adjj[x][2].push_back(p);
                ans[x] = ans[p] - 1;
               //  cerr<<3<<" "<<x<<" "<<p<<" "<<ans[p]<<" "<<ans[x]<<endl;
                continue;
            }
            else
            {
                   
                bool ok = true;
                for (auto &y : adjj[p][2])
                {
                    if (present[x][y] == 0)
                    {   
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                   adjj[p][2].push_back(x);
                adjj[x][2].push_back(p);
                    ans[x] = ans[p] - 1;
                   // cerr<<4<<" "<<x<<" "<<p<<" "<<ans[p]<<" "<<ans[x]<<endl;
                    continue;
                }
            }

             if (adjj[p][0].empty())
            {
                adjj[p][1].push_back(x);
                adjj[x][1].push_back(p);
               
                
                ans[x] = ans[p];
               //  cerr<<1<<" "<<x<<" "<<p<<" "<<ans[p]<<" "<<ans[x]<<endl;
                continue;
            }
            else
            {

                bool ok = true;
                for (auto &y : adjj[p][0])
                {  
                    if (present[x][y] == 0)
                    {  //cout<<x<<" "<<y<<" "<<present[x][y]<<endl;
    
                        ok = false;
                        
                        break;
                    }
                }

                if (ok)
                {    
                    adjj[p][1].push_back(x);
                    adjj[x][1].push_back(p);
                 
                    ans[x] = ans[p];
                  //  cerr<<2<<" "<<x<<" "<<p<<" "<<ans[p]<<" "<<ans[x]<<endl;
                    continue;
                }
            }

            cout << "NO" << endl;
            
            return;
        }
    }



    cout << "YES" << endl;

    for (int i = 1; i <= n; i++)
        cout << ans[i]+n<< " ";
    cout << endl;

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