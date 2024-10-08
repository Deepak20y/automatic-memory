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


struct p
{
    int minp,cnt,gc;
};

struct segment
{
    int sz;
    vector<p> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
            p ab{(int)1e9+7,0,0};
        tree.assign(2*sz+10, ab);
    }

    void initial(int i, p v, int x, int lx, int rx)
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

   
  p merge( p & a,p &b)
  {   
      
      p d;
       int mp=a.gc;
       int qp=b.gc;
      d.gc=gcd(mp,qp);
       
      
      if(a.minp==b.minp)
      {
         d.cnt=a.cnt+b.cnt;
         d.minp=a.minp;
      }
      else if(a.minp<b.minp)
      {
        d.cnt=a.cnt;
        d.minp=a.minp;
      }
      else 
      { 
         d.cnt=b.cnt;
        d.minp=b.minp;
      }

      return d;

  }
  
 
    p calc(int l, int r, int x, int lx, int rx)
    {  
        p a;
            a.minp=1e9+7;
            a.cnt=0;
            a.gc=0;

        if (r <= lx || rx <= l)
            return a;
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        p s1 = calc(l, r, 2 * x + 1, lx, m);
        p s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1 ,s2);
    }

    
};


 void solve(){
        
        int n;
        cin>>n;
        segment tee;
        tee.build(n);

        for(int i=0;i<n;i++)
        {   int m;cin>>m;
        // cout<<m<<" ";
            p a;
            a.minp=m;
            a.cnt=1;
            a.gc=m;
           tee.initial(i,a,0,0,tee.sz);
        }
 //cout<<endl;
  p ab=tee.calc(1,2,0,0,tee.sz);
   //cout<<ab.minp<<" "<<ab.cnt<<" "<<ab.gc<<endl;

 
       int q;cin>>q;
       
       while(q--)
       {
             int l,r;cin>>l>>r;
             l--;
           //  cout<<l<<" "<<r<<endl;
            ab=tee.calc(l,r,0,0,tee.sz);
     //  cout<<ab.minp<<" "<<ab.cnt<<" "<<ab.gc<<endl;
            if(ab.gc==ab.minp)
            {
                 cout<<r-l-ab.cnt<<endl;
            }
            else cout<<r-l<<endl;

       }
    




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}