// Topic: Rotate Image
// Description: Rotate an n x n 2D matrix by 90 degrees clockwise in-place.
// Approach: Transpose the matrix, then reverse each row. In-place, O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    // transpose
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) swap(matrix[i][j], matrix[j][i]);
    // reverse each row
    for (int i = 0; i < n; ++i) reverse(matrix[i].begin(), matrix[i].end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(mat1);
    for (int i = 0; i < (int)mat1.size(); ++i)
    {
        for (int j = 0; j < (int)mat1.size(); ++j)
            cout << mat1[i][j] << (j + 1 == (int)mat1.size() ? '\n' : ' ');
    }
    vector<vector<int>> mat2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(mat2);
    for (int i = 0; i < (int)mat2.size(); ++i)
    {
        for (int j = 0; j < (int)mat2.size(); ++j)
            cout << mat2[i][j] << (j + 1 == (int)mat2.size() ? '\n' : ' ');
    }
}

/*
Time Complexity: O(n^2)
Space Complexity: O(1) extra space
*/
