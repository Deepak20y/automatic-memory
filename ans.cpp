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

void findSubsequence(vector<int>& nums, int& k, int currIndex, long long& maximumSum, vector<int> subsequence) {
	if (currIndex == nums.size()) {
		if (subsequence.size() == k) {

            bool isIncreasing = true;

			// Declare a variable to store the sum of the subsequence.
			long long currSum = subsequence[0];

			// Check whether the subsequence is increasing or not.
			for (int i = 1; i < k; i++) {
				if (subsequence[i] < subsequence[i - 1]) {
					isIncreasing = false;
					break;
				}

				currSum += subsequence[i];

			}

			/*
				If the subsequence is increasing and the sum of this subsequence is greater
				than the sum we have gotten so far, we update the maximumSum.
			*/
			if (isIncreasing == true) {
				maximumSum = max(maximumSum, currSum);
			}

		}
        
        return;

	}

	findSubsequence(nums, k, currIndex + 1, maximumSum, subsequence);

	subsequence.push_back(nums[currIndex]);

	findSubsequence(nums, k, currIndex + 1, maximumSum, subsequence);

}

long long maximumSum(vector<int>& nums, int k) {

	// Initialize a variable to store the maximum sum of any subsequence.
	long long maximumSum = -1;
	vector<int> subsequence;

	findSubsequence(nums, k, 0, maximumSum, subsequence);

	return maximumSum;
}
 void solve(){
       

  int n , k;cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];

  cout<<maximumSum(arr , k)<<endl;;



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