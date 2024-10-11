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

ll dp[20][10][4][2][2]; // length of number ,cnt of non-zero if smaller can the number start from here

vector<int> num;
ll dsp(int pos, int cnt, int form, int small)
{   
    if(pos==num.size())
    {   if(cnt<=3)
        return 1;
        else return 0;
    }
     if(dp[pos][cnt][form][small]!=-1)return dp[pos][cnt][form][small];

    int sp=(small==1)?9:num[pos];
      ll ans=0;
    for(int i=0;i<=sp;i++)
    {
      
      if(i==0)
      {
              
      }else
      {

      }

    }





    return 0;
}

void solve()
{

    ll l, r;
    cin >> l >> r;
    while (r > 0)
    {
        num.push_back(r % 10);
        r /= 10;
    }
    reverse(num.begin(), num.end());
    for (auto &x : num)
        cout << x << " ";
    cout << endl;
    memset(dp,-1,sizeof(dp));
    ll ans = dsp(0, 0, 0, 0);

    l--;
    ll ans2 = 0;

    if (l > 0)
    {
        num.clear();
        memset(dp,-1,sizeof(dp));
        while (l > 0)
        {
            num.push_back(l % 10);
            l /= 10;
        }

        reverse(num.begin(), num.end());
        ans2 = dsp(0, 0, 0, 0);
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
    // t=1;
    while (t--)
        solve();
    return 0;
}