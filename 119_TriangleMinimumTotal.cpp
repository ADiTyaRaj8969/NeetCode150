// Topic: Triangle (Minimum Total)
// Description: Given a triangle array, return minimum path sum from top to bottom.
// Approach: Bottom-up DP modifying last row (O(n) space where n is width of triangle base).

#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
    int n = triangle.size();
    if (n == 0)
        return 0;
    vector<int> dp = triangle.back();
    for (int layer = n - 2; layer >= 0; --layer)
    {
        for (int i = 0; i <= layer; ++i) dp[i] = triangle[layer][i] + min(dp[i], dp[i + 1]);
    }
    return dp[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<int>>> tests = {
        {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}},  // expect 11
        {{-10}}                                  // expect -10
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto tri = tests[i];
        cout << "Test " << (i + 1) << ": " << minimumTotal(tri) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
