#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/

void solve()
{
    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> a(n);
    vector<ll> b(n);

    ll maxp = 0;
    
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];b[i]=a[i];
        if (maxp < a[i])
            {idx = i;maxp=a[i];}
        
    }
    for(int i=0;i<n-1;i++)b[i+1]+=b[i];

   //cout<<idx<<endl;
  
    for (int i = 0; i < n; i++)
    {

      
        if (i == 0)
        {
            if (a[0] + k >= maxp)
            {
                cout << 0 << " ";
            }
            else
                cout << 1 << " ";
        }
        else
        {      
                if(i==idx)
                {
                    if(a[0]+k<maxp)cout<<0<<" ";
                    else cout<<i<<" ";
                    continue;
                }
            
                ll sp=b[i]+k;
            
                if(sp>=maxp){cout<<i<<" ";}
                else cout<<i+1<<" ";
                
            

        }

        
    }

    cout<<endl;

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
    return 0;
}