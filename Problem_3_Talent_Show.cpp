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
    // freopen("talent.in","r",stdin);
    // freopen("talent.out","w",stdout);
    int n;
    cin >> n;
    int w;
    cin >> w;

    vector<pair<int, int>> a, b;
    int sum=0;
    for (int i = 0; i < n; i++)
    {

        int x, y;
        cin >> x >> y;
            a.push_back({y, x});
            sum+=y;
       
    }

  
    vector<vector<int>> dp(2, vector<int>(sum+4,1e9));

    int curr = 1;
    int neww = 0;
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {   
            dp[curr][j]=dp[neww][j];
            if(j-a[i-1].first>=0&&dp[neww][j-a[i-1].first]!=1e9)
            dp[curr][j]=min(dp[curr][j],dp[neww][j-a[i-1].first]+a[i-1].second);

        }
        swap(neww,curr);
    }

   // cout<<sum<<endl;
    

     //int maxp=0;
     int ans=0;

     for(int i=1;i<=sum;i++)
     if(dp[neww][i]!=-1)
     {  //cout<<i<<" "<<dp[neww][i]<<endl;
        if(dp[neww][i]!=-1&&dp[neww][i]>=w)
        ans=max(ans,(i*1000)/dp[neww][i]);
    //cout<<dp[neww][i]<<" "<<i<<endl;
     }
     cout<<ans;
    return;
}
int main()
{
   
    // int t;
    // cin>>t;
    // // t=1;
    // while(t--)
    solve();
    return 0;
}