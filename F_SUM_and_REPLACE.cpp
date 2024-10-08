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

struct segment
{
    int sz;
    vector<ll> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, 0LL);
    }

    void initial(int i, ll v, int x, int lx, int rx)
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


    ll calc(int l, int r, int x, int lx, int rx)
    {
        if (r <= lx || rx <= l)
            return 0LL;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

   
};

 int divisors[1000005]={0};

 void solve(){
       
 int n,q;cin>>n>>q;
 segment tee;
 tee.build(n);


for (int i = 1; i <= 1000000; ++i)
 for (int j = i; j <=1000000; j += i)
  ++divisors[j];

 
 set<int>b;


  for(int i=0;i<n;i++)
  {   int m;cin>>m;
       
     tee.initial(i,m,0,0,tee.sz);
     if(m>2)b.insert(i);
  }


  while(q--)
  {
    int type;
    cin>>type;
     int l,r;cin>>l>>r;

    if(type==1)
    { l--; r--;

      auto sp=b.lower_bound(l);
       queue<int>sq;
      while(sp!=b.end())
      {   
         if(*sp<=r)
         { 
            ll p=tee.calc(*sp,*sp+1,0,0,tee.sz);
             p=divisors[p];
             tee.initial(*sp,p,0,0,tee.sz);
             if(p<=2)sq.push(*sp);
             sp++;
         }
         else break;
         
      }
      while(!sq.empty())
      {
         b.erase(sq.front());
         sq.pop();
      }

    }
    else{
         l--;
     cout<<tee.calc(l,r,0,0,tee.sz)<<endl;

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