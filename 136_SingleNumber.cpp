// Topic: Single Number
// Description: Given a non-empty array of integers, every element appears twice except for one.
// Find that single one. Approach: XOR all numbers; pairs cancel out.

#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int>& nums)
{
    int x = 0;
    for (int v : nums) x ^= v;
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Embedded test cases (no stdin)
    vector<vector<int>> tests = {{2, 2, 1}, {4, 1, 2, 1, 2}, {1}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << tests[i][j];
        }
        cout << " -> " << singleNumber(tests[i]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
