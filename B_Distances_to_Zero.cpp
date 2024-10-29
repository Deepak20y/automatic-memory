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

 void solve(){
       int n;
       cin>>n;
       vector<int>a(n);
        set<int>b;
       for(int i=0;i<n;i++){cin>>a[i];if(a[i]==0)b.insert(i);}

        
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)cout<<0<<" ";
            else{
                auto low=b.lower_bound(i);
                int minp=1e9;
                if(low==b.end())
                {
                    low--;
                    minp=min(minp,abs(i-*low));
                    
                }
                else if(low==b.begin())
                { minp=min(minp,abs(i-*low));
                    
                   low++;

                   if(low!=b.end())
                    minp=min(minp,abs(i-*low));
                }
                else{
                    minp=min(minp,abs(i-*low));
                    low--;
                   minp=min(minp,abs(i-*low));

                }
                

               cout<<minp<<" ";

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