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
 int q;cin>>q;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
         b[i]=a[i];
    }
 int pt,qt;cin>>pt>>qt;

    for (int i = 0; i < n - 1; i++)
    {
        a[i + 1] += a[i];
        b[i + 1] ^= b[i];
    }
      ll ansp=0LL;
    
     ansp = a[n - 1] - b[n - 1];
   
    int r = 0;
    int x,y;
    x=0;y=n-1;

    int len = n;
    ll sp = 0LL;
  
    for (int l = 0; l < n; l++)
    {
      
        while (r < n)
        {
            ll pp;
            if (l == 0)
            {
                pp = a[r] - b[r];
            }
            else
            {
                pp = a[r] - a[l - 1] - (b[r] ^ b[l - 1]);
            }
               if (pp == ansp&&l<=r)
        { //std::cout<<pp<<endl;
            if (r - l + 1 <=len)
                {len = r - l + 1;x=l;y=r;}
            
        }
            if (pp < ansp)
                r++;
            else
                break;
        }
    

        
    }



    std::cout << x+1 << " " << y+1 << endl;

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