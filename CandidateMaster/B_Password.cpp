#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the LPS array
void computeLPSArray(const string& pat, vector<int>& lps) {
    int M = pat.length();
    lps[0] = 0; // LPS of first character is always 0
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    // Loop to calculate lps[i] for i = 1 to M-1
    while (i < M) {
        //cout<<i<<" "<<len<<endl;
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // If mismatch, reset length to lps[len - 1]
               // cout<<len<<" "<<lps[len-1]<<endl;
                len = lps[len - 1];
            } else {
                // If len is 0, then set lps[i] to 0 and move to next character
                lps[i] = 0;
                i++;
            }
        }
    }
    
}

// Utility function to print the LPS array
void printLPS(const vector<int>& lps) {
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }
    cout << endl;
}

int main() {
    string pattern = "abbaba"; // Example pattern
    int M = pattern.length();
    vector<int> lps(M);

    computeLPSArray(pattern, lps);

    // Print the LPS array
    cout << "LPS array for pattern '" << pattern << "':" << endl;
    printLPS(lps);

    return 0;
}
