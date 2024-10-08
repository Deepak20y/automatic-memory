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

 int calc(vector<int>&a)
 {
     int maxp=0;
     int minp=9;

     for(int i=0;i<a.size();i++)
     {
        maxp=max(a[i],maxp);
        minp=min(a[i],minp);
     }

     return maxp-minp;
 }
 void solve(){
       
    ll l,r;
    cin>>l>>r;

    
       if(l<=9||l==r){cout<<l<<endl;return;}

     

    int d1=log10(l)+1;
    int d2=log10(r)+1;

    if(d1<d2)
    {  //cout<<d1<<endl;
        for(int i=1;i<=d1;i++)cout<<9;
        cout<<endl;return;
    }
    

   

    vector<int>a;
    bool ok1=false;
    
    if(r-l<=20)
    {

       ll tp=l;
 int ans=9; ll mp=l;
    while(tp<=r)   
  { 
      vector<int>d;
      ll qp=tp;
    while(qp>0)
    {
        d.push_back(qp%10);
        qp/=10;
    }


     std::reverse(d.begin(),d.end());
        
      if(calc(d)<ans){ans=calc(d);mp=tp;}
      tp++;
        
       } 
       cout<<mp<<endl;return;

    }
    
    while(l>0)
    {
        a.push_back(l%10);
        l/=10;
    }

    vector<int>b;

    while(r>0)
    {
        b.push_back(r%10);
        r/=10;
    }


     reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());

           
       

//   for(auto &x:a)cout<<x<<" ";cout<<endl;
//   for(auto &x:b)cout<<x<<" ";cout<<endl;
  
  if(b[0]-a[0]>=2)
  {
     for(int i=1;i<=d1;i++)cout<<a[0]+1;
      cout<<endl;return;

  }
   
   int i=0;
    
   while(a[i]==b[i]){i++;}
     
     int maxp=a[max(i,0)];
     int minp=b[max(i,0)];
     
    

        bool ok=false;
        
   //cout<<maxp<<" "<<minp<<endl;
      //cout<<1<<endl;return;
        for(int j=i;j<a.size();j++)
        {  
           if(ok){a[j]=maxp;continue;}
           else if(a[j]<maxp){
             
            a[j]=maxp;ok=true;} 
            maxp=max(a[j],maxp);
        
        }
           ok=false;
        for(int j=i;j<a.size();j++)
        {  
           if(ok){b[j]=minp;continue;}
           else if(b[j]>minp){
            b[j]=minp;ok=true;} 

            minp=min(minp,b[j]);
           
        }

       
       

       if(calc(a)>calc(b))
       {
        for(auto &x:b)cout<<x;cout<<endl;
       }
       else{
          for(auto &x:a)cout<<x;cout<<endl;
       }

     
    

   

return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}