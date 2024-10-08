#include<bits/stdc++.h>
using namespace std;
using ll =long long int;
using ull=unsigned long long;
/*I liked you once but not anymore now
She's wearin' dresses on the border line
(Lookin' good)
Oh wakin' senses that were lost in time
(Make amends)
This liberation is the one they'll love for ages
(Hey man, I see them comin')*/
 

  int sol1(vector<int>&arr,int k)
  {
     int n = arr.size();
    int MAX_VAL =34; // Define a reasonable range for the values
    vector<vector<int>> dp(n+2, vector<int>(MAX_VAL + 1, INT_MAX));

    // Initialize the DP table for the first element
    for (int j = 0; j <=30; ++j) {
        dp[0][j] = abs(arr[0] - j);
    }

    // Fill the DP table
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <=30; ++j) {
            dp[i][j] = INT_MAX; // Initialize with a large number
            for (int m = max(0, j - k); m <= min(MAX_VAL, j + k); ++m) {
                if (dp[i-1][m] != INT_MAX) { // Ensure previous value is valid
                    dp[i][j] = min(dp[i][j], dp[i-1][m] + abs(arr[i] - j));
                }
            }
        }
    }

    // Find the minimum cost in the last row of DP table
    int result = INT_MAX;
    for (int j = 0; j <= 30; ++j) {
        result = min(result, dp[n-1][j]);
    }
    return result;
  }

 int sol(int sum,vector<int>&b,int k)
 {
       int n=b.size();
       int cnt=0;
    for(int i=1;i<n-1;i++)
    {
        while(b[i-1]<b[i]&&b[i]>b[i+1]&&sum>k){b[i]--;sum-=2;cnt++;}
        if(sum<=k)return cnt;
    }

    for(int i=1;i<n-1;i++)
    {
        while(b[i-1]>b[i]&&b[i]<b[i+1]&&sum>k){b[i]++;sum-=2;cnt++;}
        if(sum<=k)return cnt;
    }

     // cout<<k<<endl;
    //  cout<<cnt<<endl;
    //  for(auto &x:b)cout<<x<<" ";cout<<endl;
      
          int p=sol1(b,k);
      
      return cnt+p;
    


 }

 int calc(vector<int>&b)
 {

     int sum=0;

     for(int i=1;i<b.size();i++)
     {
             
             sum+=abs(b[i]-b[i-1]);
     }

     return sum;
 }

 void solve(){
       int n;
       cin>>n;
         int q;cin>>q;
        vector<int>a(n);


        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

       //for(auto &x:a)cout<<x<<" ";cout<<endl;
       // return;



       while(q--)
       { 
        vector<int>b;

         int l,r;cin>>l>>r;
         l--;
         r--;
         int k;cin>>k;

         for(int i=l;i<=r;i++)
         {
           b.push_back(a[i]);
         }

       //  for(auto &x:b)cout<<x<<" ";cout<<endl;

         //return;
          int sp=calc(b);
        if(sp<=k){cout<<0<<endl;continue;}
        else{
         
          int cnt=sol(sp,b,k);
           cout<<cnt<<endl;

        }


       }




return;
}
int main()
{
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;
cin>>t;
// t=1;
while(t--)
solve();
return 0;
}