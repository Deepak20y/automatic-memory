#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countPositiveSubarrays(vector<int>& arr) {
    unordered_map<int, int> prefixCount;
    int prefix_sum = 0;
    int count = 0;
    
    // We count an empty prefix sum (zero sum) at the start
    prefixCount[0] = 1;
    
    for (int i = 0; i < arr.size(); i++) {
        // Update the prefix sum
        prefix_sum += arr[i];
        
        // If the prefix_sum is positive, we count this subarray
        if (prefix_sum > 0) {
            count++;
        }
        
        // Check for subarrays that end at the current index and have a positive sum
        for (int sum = 1; sum <= prefix_sum; sum++) {
            if (prefixCount.find(prefix_sum - sum) != prefixCount.end()) {
                count += prefixCount[prefix_sum - sum];
            }
        }
        
        // Record the current prefix sum in the map
        prefixCount[prefix_sum]++;
    }
    
    return count;
}

int main() {
     int t;
     cin>>t;
     while(t--)
    { int n;cin>>n;
      vector<int>arr(n); 

      for(int i=0;i<n;i++)cin>>arr[i];
    cout <<countPositiveSubarrays(arr)<<endl;

    }
    return 0;
}
