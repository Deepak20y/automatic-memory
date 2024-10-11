#include<iostream>
#include<vector>
#include<cstring>
#include<numeric>
using namespace std;
using ll =long long int;
using ull=unsigned long long;


  
  int divisor[10000007];
  vector<int>ans1,ans2;
 void solve(){
    

  memset(divisor,-1,sizeof(divisor));

    for(int i=2;i<=1e7;i++)
    {  
       if(divisor[i]==-1)
       for(int j=2*i;j<=1e7;j+=i)
       {
           if(divisor[j]==-1)
           divisor[j]=i;
       }
    }
    int n;cin>>n;

   //for(int i=1;i<=20;i++)cout<<i<<" "<<divisor[i]<<endl;
 

  for(int i=0;i<n;i++)
  {
     int m;cin>>m;
    
    if(divisor[m]==-1)
    {
        ans1.push_back(-1);
        ans2.push_back(-1);
    }
    else{

        int mp=m;
        while(mp%divisor[m]==0)mp/=divisor[m];

        int tp=mp+divisor[m];
        

         if(mp==1||gcd(m,tp)>1)
         {
            ans1.push_back(-1);
        ans2.push_back(-1);
         }
         else{
            ans1.push_back(mp);
        ans2.push_back(divisor[m]);
         }


    }

     

     

  }

  for(auto &x:ans1)cout<<x<<" ";cout<<"\n";
  for(auto &x:ans2)cout<<x<<" ";cout<<"\n";



return;
}
int main()
{

    //  setTimeLimit(4); 
    //  setMemoryLimit(1000);
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}