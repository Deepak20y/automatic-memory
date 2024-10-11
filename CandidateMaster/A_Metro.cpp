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
    int s;
    cin >> s;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    s--;

   
        bool ok = false;
        if (s == 0)
            ok = true;
        // cout<<s<<endl;
        int p = -1;
        if (a[0] == 1)
            for (int i = 1; i < n; i++)
            {
                if (a[i] == 1 && b[i] == 1)
                    p = i;

                if (a[s] != 0)
                    ok = true;
            }

          
   //   cout<<ok<<endl;cout<<p<<endl;
      //cout<<s<<endl;
           if (p != -1)
            for (int i = p; i >= 0; i--)
            {
               // cout<<i<<' '<<(int)ok<<"\n";
                if (b[i] != 0&&s==i)
                    ok = true;
            }

           // cout<<ok<<endl;

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
        solve();
    return 0;
}