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
 struct ed
 {
     int l,r,q;
     
 };

 struct segment
{
    int sz;
    vector<int> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
          
        tree.assign(2*sz+10,0);
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
        tree[x] =tree[2 * x + 1]& tree[2 * x + 2];
    }

   

    int calc(int l, int r, int x, int lx, int rx)
    {  
      

        if (r <= lx || rx <= l)
            return ((1<<30)-1);
        if (l <= lx && r >= rx)
            return tree[x];
        int m = (lx + rx) / 2;
        int s1 = calc(l, r, 2 * x + 1, lx, m);
        int s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1&s2;
    }

    
};

 void solve(){
       int n;cin>>n;
       int m;cin>>m;
       vector<vector<int>>dp(35,vector<int>(n,0));

         
        vector<ed>a(m);

  for(int i=0;i<m;i++)
  {
     
     cin>>a[i].l>>a[i].r>>a[i].q;

     a[i].l--;
   for(int j=0;j<30;j++)
   {
       if((1<<j)&a[i].q)
       {
          dp[j][a[i].l]++;
          if(a[i].r<n)dp[j][a[i].r]--;
       }
   }

  }
     
     for(int j=0;j<30;j++)
     {
        for(int i=0;i<n-1;i++)
        {
            dp[j][i+1]+=dp[j][i];
        }
     }
      
    segment tee;
    tee.build(n);

     for(int i=0;i<n;i++)
     {

        int ans=0;

        for(int j=0;j<30;j++)
        {
             if(dp[j][i]>0)ans|=(1<<j);
        }
     tee.initial(i,ans,0,0,tee.sz);
     }

 bool ok=true;;
     for(int i=0;i<m;i++)
     {
        
        int sp=tee.calc(a[i].l,a[i].r,0,0,tee.sz);
        if(sp!=a[i].q)ok=false;
     }

    
    if(ok){cout<<"YES"<<endl;
 
        for(int i=0;i<n;i++)
        {
            cout<<tee.calc(i,i+1,0,0,tee.sz)<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}