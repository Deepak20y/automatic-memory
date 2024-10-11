#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string tr = "1";

bool ask(string &s)
{

    cout << "? " << s << endl;
    if (tr.find(s) != std::string::npos)
        return true;
    else
        return false;
    int p;
    cin >> p;
    return p;
}

void solve()
{
    int n;
    cin >> n;
    string ans = "";
    string p = "";

    while (1)
    {
        p.push_back('0');
        bool ok = ask(p);
        if (ok)
        {
            ans.push_back('0');
        }
        else
        {
            p.pop_back();
            p.push_back('1');
            if (p.size() == 1)
            {

                ans.push_back('1');
            
            }
          else if(ask(p)) 
                ans.push_back('1');
            else
            {
                p.pop_back();
                break;
            }
        }
        if (ans.size() == n)
            break;
    }


    if (ans.size() != n)
        while (1)
        {
            reverse(p.begin(), p.end());
            p.push_back('0');
            reverse(p.begin(), p.end());


            bool ok = ask(p);
            if (ok)
            {
                reverse(ans.begin(), ans.end());
                ans.push_back('0');
                reverse(ans.begin(), ans.end());
            }
            else
            {
                reverse(p.begin(), p.end());
                p.pop_back();
                p.push_back('1');
                reverse(p.begin(), p.end());

                 reverse(ans.begin(), ans.end());
                ans.push_back('1');
                reverse(ans.begin(), ans.end());

                
            }


            if (ans.size() == n)
                break;
        }

    cout << "! " << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
