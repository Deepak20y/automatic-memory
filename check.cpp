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
 
 

/*
    Time Complexity: O(K * nCk)
    Space Complexity: O(K * nCk)

	Where 'N' is the number of elements in the array, 'K' is the size of the subsequence.
*/

long long correct(vector<int>& nums, int k) {

	/*
		The value of MAXSUMS[i][j] represents maximum sum for any subsequence 
		of length j and ending at index i.
	*/
	int numsLen = nums.size();

	long long maxSum[numsLen][k + 1];

	// Initialize all the values of the 'MAXSUM' table with -1.
	for (int i = 0; i < numsLen; i++) {
		for (int j = 0; j < k + 1; j++) {
			maxSum[i][j] = -1;
		}
	}

	/*
		For each index, the maximum sum of a subsequence having a length of 1 is 
		the value of the element at that index.
	*/
	for (int idx = 0; idx < numsLen; idx++) {
		maxSum[idx][1] = nums[idx];
	}

	/*
		Here 'ENDIDX' represents the ending index of the subsequence, and
		size represents the size of the subsequence. 
	*/
	for (int endIdx = 1; endIdx < numsLen; endIdx++) {
		for (int prev = 0; prev < endIdx; prev++) {

			if (nums[endIdx] >= nums[prev]) {
				for (int size = 2; size <= k; size++) {
					if (maxSum[prev][size - 1] != -1) {
						maxSum[endIdx][size] = max(maxSum[endIdx][size], 
							maxSum[prev][size - 1] + nums[endIdx]);
					}
				}
			}
			
		}
	}

	long long maximumSum = -1;

	for (int endIdx = 0; endIdx < numsLen; endIdx++) {
		maximumSum = max(maximumSum, maxSum[endIdx][k]);
	}

	return maximumSum;

}

long long maximumSum(vector<int>& nums, int k) {
	// Write your code here.
    int n = nums.size();
    if(k>n){
        return LLONG_MIN;
    }
    vector<vector<long long int>>dp(n+1 , vector<long long int>(k+1,LLONG_MIN));
	for(int i=0;i<n;i++){
		dp[i][0]=0;
	}
    for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			if(i==1){
				dp[j][i] = nums[j];continue;
			}
            for(int l=0;l<j;l++){
				if(nums[l]<=nums[j] && dp[l][i-1]!=LLONG_MIN){
                   dp[j][i] = max(dp[j][i] , dp[l][i-1] + nums[j]);
				}
			}
		}
	}
    long long int ans = LLONG_MIN;
    for(int i=0;i<n;i++){
         ans = max(ans , dp[i][k]);
    }
	if(ans==LLONG_MIN){
		return -1;
	}
     for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
     }
	return ans;
}

 void solve(){
       

   int n ,k;cin>>n>>k;
   vector< int > arr;
   for(int i=0;i<n;i++){
    int x;cin>>x;arr.push_back(x);
   }
  long long int result = maximumSum(arr , k);
   cout<<result<<endl;

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