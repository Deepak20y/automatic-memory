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

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;

struct spd
{
      ll minp1,minp2;
};
struct segment
{
    int sz;
    vector<spd> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
            spd ab{(ll)1e14,(ll)1e14};
        tree.assign(2*sz+10, ab);
    }

    void initial(int i, spd v, int x, int lx, int rx)
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

   
    spd merge(spd &a ,spd &b)
    {  spd d;

         d.minp1=min(a.minp1,b.minp1);
         d.minp2=min(a.minp2,b.minp2);

        return d;
    }
  

    spd calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return {(ll)1e14,(ll)1e14};
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        spd s1 = calc(l, r, 2 * x + 1, lx, m);
        spd s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1 ,s2);
    }

};




 void solve(){
        int n;
        cin>>n;
        int q;cin>>q;
          
          segment tee;
          tee.build(n);
         
        for(int i=0;i<n;i++)
        {
           int m;cin>>m;
           spd ab{m+i,m+n-i-1};
           tee.initial(i,ab,0,0,tee.sz);

        }

  while(q--)
  {
     int type;
     cin>>type;
     if(type==1)
     { 
        int k;ll x;cin>>k>>x;
        k--;
          spd ab{x+k,x+n-k-1};  
           tee.initial(k,ab,0,0,tee.sz);        
     }
     else{
          
          
          int idx;
          cin>>idx;
          idx--;
          ll minp=tee.calc(idx,idx+1,0,0,tee.sz).minp1-idx;

          if(idx-1>=0)
          {
            minp=min(minp,tee.calc(0,idx,0,0,tee.sz).minp2-(n-idx-1));
          }

          if(idx+1<n)
          {
          minp=min(minp,tee.calc(idx,n,0,0,tee.sz).minp1-idx);

          }
        
        cout<<minp<<endl;



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