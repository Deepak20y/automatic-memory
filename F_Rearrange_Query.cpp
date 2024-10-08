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
const ll mod=1e9+7;

long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0,mod-1LL)(gen);
}
 // virtually impossible to hack
 void solve(){
        
       int n;cin>>n;
       int q;cin>>q;
        vector<ll>hash(n+5);
        for(int i=1;i<=n;i++)
        {
           hash[i]=rng();
        }
           vector<int>a(n),b(n);

           for(int i=0;i<n;i++)cin>>a[i];
           for(int i=0;i<n;i++)cin>>b[i];

        //    for(auto &x:a)cout<<x<<" ";cout<<endl;
        //    for(auto &x:b)cout<<x<<" ";cout<<endl;

       //for(auto &x:hash)cout<<x<<" ";cout<<endl;



        vector<ll>hash_a(n+4),hash_b(n+4);

        for(int i=0;i<n;i++)
        {
            
               hash_a[i+1]=(hash_a[i]+hash[a[i]])%mod;
               hash_b[i+1]=(hash_b[i]+hash[b[i]])%mod;

        }

         


        while(q--)
        {

             int l,r;cin>>l>>r;
            int L,R;cin>>L>>R;
             if((hash_a[r]-hash_a[l-1]+mod)%mod==(hash_b[R]-hash_b[L-1]+mod)%mod)cout<<"Yes"<<endl;
             else cout<<"No"<<endl;

        }
        





return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

solve();
return 0;
}