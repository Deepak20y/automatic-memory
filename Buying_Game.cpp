#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to read and process a single test case
void processTestCase(int numPairs) {
    long long totalSum = 0, minSum = 0;
    vector<pair<long long, long long>> pairs(numPairs);

    // Read the first value of each pair
    for (auto &[firstValue, secondValue] : pairs) {
        cin >> firstValue;
    }

    // Read the second value of each pair, modify firstValue, and calculate totalSum of all secondValue values
    for (auto &[firstValue, secondValue] : pairs) {
        cin >> secondValue;
        firstValue -= secondValue;  // Update firstValue by subtracting secondValue
        totalSum += secondValue;    // Add secondValue to totalSum
    }

    // Sort the vector based on the modified firstValue values
    sort(pairs.begin(), pairs.end());

    // Initialize minSum with the total sum of secondValue values
    minSum = totalSum;
    totalSum += pairs[0].first; // Initialize totalSum with the first element's modified firstValue

    // Iterate through the sorted vector, adding each firstValue to totalSum and updating minSum
    for (int i = 1; i < numPairs; i++) {
        totalSum += pairs[i].first;
        minSum = min(minSum, totalSum); // Track the minimum sum
    }

    // Output the result
    cout << minSum << "\n";
}

// Main function to handle multiple test cases
void solve() {
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int numPairs;
        cin >> numPairs;
        processTestCase(numPairs);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}