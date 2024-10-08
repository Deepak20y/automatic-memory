#include<stdio.h>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    if(min(a,b)==0)return max(a,b);
	while(b ^= a ^= b ^= a = a % b);
	return a;
}
struct segment
{
    int sz;
    vector<int> tree;
   
   void build(int n) {  // build the tree
         sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, 0);
         
}

void initial(int p, int value,int n) {  // set value at position p
  for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] =gcd(tree[p],tree[p^1]);
}

int calc(int l, int r,int n) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res= gcd(tree[l++],res);
    if (r&1) res= gcd(tree[--r],res);
  }
  return res;
}

    int find(int k, int lx, int rx,int n)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        int m = (rx + lx) / 2;
        int var=calc(lx,m,n);
        if(var%k!=0)
        {
           return find(k,lx,m,n);
        }
        else return find(k,m,rx,n);
       
    }
};



 void solve(){
       
  int n;scanf("%d",&n);
   segment tee;
   tee.build(n);
   for(int i=0;i<n;i++)
   { int m; scanf("%d",&m);
     tee.initial(i,m,n);
   }
    
    int q;scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        int type;
        scanf("%d",&type);

        if(type==1)
        {
           int l,r,x;
           scanf("%d",&l);
           scanf("%d",&r);
           scanf("%d",&x);

           int ans=tee.calc(l-1,r,n);
           if(ans==x||r-l==0||x==1)printf("YES\n");
           else
           {   bool ok=true;
               int mp=tee.find(x,l-1,r,n);
                
                if(l-1!=mp)
                {
                    int sp=tee.calc(l-1,mp,n);
                    if(sp%x!=0&&sp!=0)ok=false;
                }

                if(r-1!=mp)
                {
                    int sp=tee.calc(mp+1,r,n);
                    if(sp%x!=0&&sp!=0)ok=false;
                }
                if(ok)printf("YES\n");
                else printf("NO\n");

           }
           
            
        }
        else{  
             int idx;int m;
             scanf("%d",&idx);
             scanf("%d",&m);
             idx--;
             tee.initial(idx,m,n);
        }
      


    }




return;
}
int main()
{
// std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}