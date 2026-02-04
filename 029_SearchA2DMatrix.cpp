// Topic: Search a 2D Matrix
// Description: Determine if target exists in sorted 2D matrix (rows and columns sorted such that
// flatten is sorted). Approach: Treat matrix as flattened sorted array and binary search.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        int val = matrix[mid / n][mid % n];
        if (val == target)
            return true;
        if (val < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<vector<int>>> mats = {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, {{1}}};
    vector<int> targets = {3, 2};
    for (size_t i = 0; i < mats.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": target=" << targets[i] << " -> "
             << (searchMatrix(mats[i], targets[i]) ? "true" : "false") << "\n";
    }
}

/*
Time Complexity: O(log(m*n)) = O(log m + log n)
Space Complexity: O(1)
*/
