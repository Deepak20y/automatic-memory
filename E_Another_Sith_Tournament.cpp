#include <bits/stdc++.h>
#define maxn 20
#define maxm 1000005
#define mod 1000000007
using namespace std;
typedef long long ll;
double mapp[maxn][maxn];
double dp[maxm][maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &mapp[i][j]);
        }
    }


    int tp = (1 << n) - 1;
    dp[1][0] = 1;
    for (int i = 0; i <= tp; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)))//j shoul be active in i the nask
            {
                for (int k = 0; k < n; k++)
                {
                    if (i & (1 << k)) // k should be active in i th mask
                    {
                        dp[i][j] = max(dp[i][j], dp[i ^ (1 << j)][k] * mapp[k][j] + dp[i ^ (1 << k)][j] * mapp[j][k]);
                    }
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[tp][i]);
    }
    printf("%.10lf\n", ans);
}
