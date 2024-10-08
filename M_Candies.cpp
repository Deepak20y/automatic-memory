// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// using ull = unsigned long long;
// /*I liked you once but not anymore now
// She's wearin' dresses on the border line
// (Lookin' good)
// Oh wakin' senses that were lost in time
// (Make amends)
// This liberation is the one they'll love for ages
// (Hey man, I see them comin')*/
// int n;
// int K;
// vector<int> a;
// ll dp[101][100005];
// const int mod = 1e9 + 7;
// int recur(int i, int k)
// {
//     if (k > K)
//         return 0;
//     if (i >= n)
//     {
//         if (k == K)
//             return 1;
//         else
//             return 0;
//     }
//     if (dp[i][k] != -1)
//         return dp[i][k];

//     ll ans = 0;

//     for (int j = 0; j <= a[i] && k + j <= K; j++)
//     {
//         ans += recur(i + 1, k + j);
//         ans %= mod;
//     }

//     return dp[i][k] = ans;
// }
// void solve()
// {

//     cin >> n;
//     cin >> K;
//     memset(dp, -1, sizeof(dp));
//     a.resize(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];


//    for(int i=0;i<n;i++)
//    {

//      for(int j=0;j<=k;j++)
//      {

         

//      }

//    }

//     return;
// }
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);

//     solve();
//     return 0;
// }