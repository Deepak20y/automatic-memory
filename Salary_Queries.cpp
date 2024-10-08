#include <stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


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
            tree[x]=tree[x]+ v;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            initial(i, v, 2 * x + 1, lx, m);
        else
            initial(i, v, 2 * x + 2, m, rx);
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
}tee;
struct p
{
    char x;
    int y,z;
};

vector<int>a;
vector<p>b;
 vector<int> num;
 unordered_map<int, int>c;
void solve()
{
    int n;
    scanf("%d",&n);
    int q;
    scanf("%d",&q);

    a.resize(n);
    b.resize(q);
   
    for (int i = 0; i < n; i++)
    {
         scanf("%d",&a[i]);
        num.push_back(a[i]);
    }
  
    for (int i = 0; i < q; i++)
    {  cin>>b[i].x>>b[i].y>>b[i].z;
         //printf("%c",b[i].x);
     
        num.push_back(b[i].z);
        num.push_back(b[i].y);
    }
    num.push_back(0);
    num.push_back(1e9+4);

    //for(auto &x:num)cout<<x<<" ";cout<<endl;

   
    sort(num.begin(), num.end());
    int cnt = 0;
    for (int i = 0; i < num.size(); i++)
    {
        while (i != n - 1 && num[i] == num[i + 1])
            i++;

        c[num[i]] = cnt++;
    }
  
//  for(auto &x:num)
//  {
//      cout<<x<<" "<<c[x]<<endl;
//       }


//   for(auto &x:a)cout<<x<<" ";cout<<endl;
 //cout<<c[4]<<" "<<c[6]<<endl;
    tee.build(cnt);

    for (int i = 0; i < n; i++)
    {
        tee.initial(c[a[i]], 1, 0, 0, tee.sz);
    }

    for (int i = 0; i < q; i++)
    {
        if (b[i].x == '?')
        {
            printf("%d \n",tee.calc(c[b[i].y], c[b[i].z] + 1, 0, 0, tee.sz));
        }
        else
        {
            b[i].y--;

            tee.initial(c[a[b[i].y]], -1, 0, 0, tee.sz);
            a[b[i].y] = b[i].z;
            tee.initial(c[b[i].z], 1, 0, 0, tee.sz);
        }
    }

    return;
}
int main()
{
 
 
        solve();
    return 0;
}