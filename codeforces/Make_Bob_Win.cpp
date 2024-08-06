#include<bits/stdc++.h>

using namespace std;


void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    int m = 0;
    int n1=0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (i+1 < n && s[i] == s[i + 1])
        {
            cnt++;
            i++;

        }

        if (s[i] == '0') n1++;
        else m++;

    }
   
    // cout<<m<<" "<<n1<<endl;
    if (m > n1) {
        cout << 0 << endl;
        return;
    }
    else
    {


        if (m == n1)
        {
            int cnt = 0; // cout<<"pp"<<endl;
            if (s[0] == '0')
            {
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '0') cnt++;
                    else break;
                }
            }
            else
            {

                for (int i = n - 1; i >= 0; i--)
                {
                    if (s[i] == '0') cnt++;
                    else break;
                }
            }
            cout << cnt << endl;
        }
        else
        {
            int cnt = 0;
            
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0') {
                    cnt++;
                }
                else break;
            }
            int ansp = cnt;
            
          
             cnt=0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0') {
                    cnt++;
                }
                else break;
            }
         
        
         if(m==0)cout<<ansp<<endl;
         else cout<<ansp+cnt<<endl;
          
           




        }
    }




    return;
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;

}