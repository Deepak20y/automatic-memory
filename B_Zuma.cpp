#include<bits/stdc++.h>
using namespace std;

// find if the subarray is  a palindrome or not
bool ispalindrome[505][505];
void Palindrome(vector<int>& arr) {
   int n=arr.size();

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)ispalindrome[i][j]=false;

  for(int i=0;i<n;i++)ispalindrome[i][i]=true;;

  for(int i=0;i<n-1;i++)if(arr[i]==arr[i+1])ispalindrome[i][i+1]=true;




  for(int i=2;i<n;i++)
  {
    for(int j=0;j<n-i;j++)
    {
      
       int p=j;
       int q=j+i;

    if(ispalindrome[p+1][q-1]&&arr[p]==arr[q])ispalindrome[p][q]=true;
       
    }


  }

    return;
}

// Function to calculate the minimum number of steps to remove all elements
int minStepsToRemovePalindromes(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Single elements are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;  // single elements are palindromes
    }


    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;

            // If the entire subarray is a palindrome
            if (ispalindrome[i][j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = INT_MAX;

                // Try splitting the subarray into two parts
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }

                //  if arr[i] == arr[j], consider reducing it
                if (arr[i] == arr[j]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
    }


    return dp[0][n - 1];
}

int main() {
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
      Palindrome(a);
      cout<<minStepsToRemovePalindromes(a)<<endl;

    return 0;
}
