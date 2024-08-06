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

    string s;
    cin >> s;

    vector<int> a(26, 0);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        a[s[i] - 'a']++;
    }

    s = "";
 
    vector<pair<int, int>> c;

    for (int i = 0; i < 26; i++)
    {
        if (a[i] > 0)
            c.push_back({i, a[i]});
    }
    //  cout<<c.size()<<endl;
    if (c.size() == 2)
    {
        for (int i = 0; i < 25; i++)
        {
            if (a[i] > 0 && a[i + 1] > 0)
            {
                cout << "No answer" << endl;
                return;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (a[i] > 0)
            {
                while (a[i]--)
                    s.push_back('a' + i);
            }
        }
    }
    else if (c.size() == 3)
    {
        for (int i = 0; i < 24; i++)
        {
            if (a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0)
            {
                cout << "No answer" << endl;return;
            }
        }

        if (c[0].first+1 == c[1].first)
        {
            while (c[0].second--)
                s.push_back(c[0].first + 'a');
            while (c[2].second--)
                s.push_back(c[2].first + 'a');
            while (c[1].second--)
                s.push_back(c[1].first + 'a');
        }
        else if (c[1].first +1== c[2].first)
        {
            while (c[2].second--)
                s.push_back(c[2].first + 'a');
            while (c[0].second--)
                s.push_back(c[0].first + 'a');
            while (c[1].second--)
                s.push_back(c[1].first + 'a');
        }
        else
        {
            while (c[2].second--)
                s.push_back(c[2].first + 'a');
            while (c[0].second--)
                s.push_back(c[0].first + 'a');
            while (c[1].second--)
                s.push_back(c[1].first + 'a');
        }
    }
    else
    {
        if(c.size()>0)
        for (int i = 1; i < c.size(); i += 2)
        {
            while (c[i].second--)
                s.push_back(c[i].first + 'a');
        }

        for (int i = 0; i < c.size(); i += 2)
        {
            while (c[i].second--)
                s.push_back(c[i].first + 'a');
        }
    }

    cout << s << endl;

    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;cin>>t;
   // return 0;
    while(t--)
    solve();
    return 0;
}