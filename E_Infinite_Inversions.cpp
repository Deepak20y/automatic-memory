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
    vector<int> tree;
    void build(int n)
    {
        sz = 1;
        while (sz <n)
            sz *= 2;
        tree.assign(2*sz+10, 0);
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

   
};







 void solve(){
        int n;cin>>n;

        vector<pair<int,int>>a(n);
       
       map<int,int>b;// it will store the swap position

      for(int i=0;i<n;i++)
      {
         cin>>a[i].first>>a[i].second;

         if(b[a[i].first]==0)b[a[i].first]=a[i].first;
          if(b[a[i].second]==0)b[a[i].second]=a[i].second;
          swap(b[a[i].first],b[a[i].second]);
      }
       vector<int>pos;
      
      map<int,int>c;
      int cnt=0;
    int minp=1e9+9;
      for(auto &[x,y]:b)
      {  minp=min(minp,x);
         c[x]=cnt++;
         pos.push_back(x);
      }

    //   for(auto &[x,y]:b)cout<<x<<" "<<y<<endl;
    //   cout<<endl;

    //   for(auto &x:pos)cout<<x<<" ";cout<<endl;
 
   n=pos.size();
      segment tee ;
      tee.build(n);
  ll ans=0LL;

   //for(auto &[x,y]:b)cout<<x<<" "<<y<<endl;
// cout<<minp<<endl;
 
      for(int i=0;i<n;i++)
      {
         // cout<<pos[i]<<" "<<b[pos[i]]<<" "<<c[b[pos[i]]]<<endl;
            
             if(minp==b[pos[i]]){ans+=(pos[i]-1)-(b[pos[i]]-1);}
             else if(pos[i]<=b[pos[i]])
            {
                int pp=tee.calc(c[b[pos[i]]],n,0,0,tee.sz);
                //cout<<pos[i]<<" "<<p
               // cout<<i<<" "<<pp<<endl;
                ans+=pp;
            }
            else {
                
                int sp=lower_bound(pos.begin(),pos.end(),b[pos[i]])-pos.begin();
                int msp=lower_bound(pos.begin(),pos.end(),pos[i])-pos.begin();
        
                
           sp=msp-sp-1;
         
      
                ans+=tee.calc(c[pos[i]],n,0,0,tee.sz);

                int mp=pos[i]-b[pos[i]]-1;
               
                int qp=sp-tee.calc(c[b[pos[i]]],c[pos[i]],0,0,tee.sz);
                ans+=mp-qp;
             //cout<<mp-qp<<endl;
           
            }
     


        tee.initial(c[b[pos[i]]],1,0,0,tee.sz);
       if(i+1<n)
       { 
          if(pos[i]+1!=pos[i+1])
          {   
              int sp=upper_bound(pos.begin(),pos.end(),pos[i])-pos.begin();
              
              ll mp=tee.calc(c[pos[sp]],n,0,0,tee.sz);
              ll qt=pos[i+1]-pos[i]-1;
           //cout<<qt<<endl;
              ans+=mp*qt;
        
          }

       }

      }
     



     
 std::cout<<ans;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}