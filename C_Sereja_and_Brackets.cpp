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
  
struct sp
{
    int open,close,sum;
};

struct segment
{
    int sz;
    vector<sp> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
            sp sl={0,0,0};
        tree.assign(2*sz+10, sl);
    }

    void initial(int i, sp v, int x, int lx, int rx)
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
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
      
      sp merge(sp &a,sp &b)
      {
         sp c={0,0,0};
          int mp=a.open;
          int qp=b.close;
         int p=min(mp,qp);
         c.sum=a.sum+b.sum+p;
         c.open=a.open+b.open-p;
         c.close=a.close+b.close-p;
         return c;
      }
   

  

    sp calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return {0,0,0};
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        sp s1 = calc(l, r, 2 * x + 1, lx, m);
        sp s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1 ,s2);
    }

    
};




 void solve(){
       
string s;cin>>s;
int q;
cin>>q;
   int n=s.size();
   segment tee;
   tee.build(n);

  for(int i=0;i<n;i++)
  {
     sp ac{0,0,0};
     if(s[i]=='(')ac.open=1;
     else ac.close=1;
      tee.initial(i,ac,0,0,tee.sz);
  }




while(q--)
{
   int a,b;cin>>a>>b;
     a--;

     sp lp=tee.calc(a,b,0,0,tee.sz);
     cout<<2*lp.sum<<endl;

}




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}