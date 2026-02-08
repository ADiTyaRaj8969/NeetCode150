// Topic: Minimum Path Sum
// Description: Given a m x n grid of non-negative numbers, find a path from top-left to
// bottom-right which minimizes sum of all numbers along its path. Approach: DP in-place or with
// O(n) rolling array. We'll use in-place modification of grid for simplicity.

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int top = (i > 0) ? grid[i - 1][j] : INT_MAX;
            int left = (j > 0) ? grid[i][j - 1] : INT_MAX;
            grid[i][j] += min(top, left);
        }
    }
    return grid[m - 1][n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<int>>> tests = {
        {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},  // expect 7
        {{1, 2, 3}, {4, 5, 6}},             // expect 12
        {{5}}                               // expect 5
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto grid = tests[i];
        cout << "Test " << (i + 1) << ": " << minPathSum(grid) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(m*n)
Space Complexity: O(1) extra (in-place)
*/
