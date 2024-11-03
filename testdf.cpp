#include <iostream>
#include <vector>
using namespace std;

void borderTraversal(const vector<vector<int>>& matrix, int n, int m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse the top row from left to right
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Traverse the right column from top to bottom
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        // Traverse the bottom row from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Traverse the left column from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    int n = 2, m = 4;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
       
    };

    cout << "Border-wise traversal: ";
    borderTraversal(matrix, n, m);
    return 0;
}
