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
int maxp;
int nsm;
unordered_map<ll,int>bc;
void compute_hash(vector<int>&s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for ( int  c : s) {
        hash_value = (hash_value + c * p_pow) % m;
        p_pow = (p_pow * p) % m;
         bc[hash_value]++;
       //  cout<<hash_value<<" "<<bc[hash_value]<<endl;
         if(bc[hash_value]==nsm)
         maxp++;
    }

}

 void solve(){
       
   int n;
 maxp=0;
 cin>>n>>nsm;

 

 for(int i=0;i<nsm;i++)
 {   vector<int>a(n);
    for(int j=0;j<n;j++)cin>>a[j];
    
     while(!a.empty()){compute_hash(a);
     reverse(a.begin(),a.end());
      a.pop_back();
       reverse(a.begin(),a.end());
     }

 }

 cout<<maxp<<endl;




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}