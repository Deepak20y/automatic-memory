#include <iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

struct segment
{
    int sz;
    vector<int> tree;
    void build(int n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(2 * sz + 10, 0);
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
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
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
        return max(s1, s2);
    }

    int find(int k, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        int m = (rx + lx) / 2;
        int var = calc(lx, m, 0, 0, sz);
        if (k <= var)
        {
            return find(k, lx, m);
        }
        else
            return find(k, m, rx);
    }
};



void solve()
{

    int n;
    cin >> n;

    vector<pair<char,pair<int,int>>>point;
    
    vector<int>d;
    for (int i = 0; i < n; i++)
    {   string st;cin>>st;
         int x1,y1;cin>>x1>>y1;
        point.push_back({st[0],{x1,y1}});
        d.push_back(x1);
    }

   // for(auto &[x,y,z]:point)cout<<x<<" "<<y<<" "<<z<<endl;
   //for(auto &x:d)cout<<x<<" ";cout<<endl;

    unordered_map<int, int> ee;
    int cnt = 0;
    vector<int> original;
    sort(d.begin(),d.end());
    int mm=d.size();
    for(int i=0;i<mm;i++)
    {
        ee[d[i]]=cnt++;
        while(i+1<mm&&d[i]==d[i+1])i++;
        original.push_back(d[i]);
    }
  
    vector<set<int>>table(cnt+1);
 
    //for(auto &x:original)cout<<x<<" ";cout<<endl;


    segment tee;
    tee.build(cnt+1);
 cnt++; 
 
    for (int i = 0; i < n; i++)
    {   int x1=ee[point[i].second.first];
        int y1=point[i].second.second;

        if (point[i].first =='a')
        {
             table[x1].insert(y1);
             auto sp = table[x1].end();
                sp--;
                
            tee.initial(x1,*sp, 0, 0, tee.sz);
        
            
        }
        else if (point[i].first =='r')
        {
            if (table[x1].size() == 1)
            {
                tee.initial(x1, 0, 0, 0, tee.sz);
                table[x1].erase(y1);
            }
            else
            {
                table[x1].erase(y1);
                auto sp = table[x1].end();
                sp--;
                
                tee.initial(x1, *sp, 0, 0, tee.sz);
            }
        }
        else
        {

            int p =tee.calc(x1+1,cnt,0,0,tee.sz);
            if (p<=point[i].second.second)
                cout << -1 <<'\n';
            else
            {
                int mp=tee.find(y1+1,x1+1,cnt);
                auto sp = table[mp].upper_bound(y1);
                cout << original[mp] << " " << *sp <<'\n';
            }
        }
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