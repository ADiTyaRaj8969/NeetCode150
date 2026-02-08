// Topic: Single Number II
// Description: Given an array of integers, every element appears three times except for one which
// appears once. Find that single one. Approach: Count bits modulo 3 across 32 bit positions.

#include <bits/stdc++.h>
using namespace std;

int singleNumberII(const vector<int>& nums)
{
    vector<int> bits(32, 0);
    for (int v : nums)
    {
        for (int i = 0; i < 32; ++i)
            if (v & (1 << i))
                bits[i]++;
    }
    int res = 0;
    for (int i = 0; i < 32; ++i)
        if (bits[i] % 3)
            res |= (1 << i);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Embedded tests (no stdin)
    vector<vector<int>> tests = {{2, 2, 3, 2}, {0, 1, 0, 1, 0, 1, 99}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << tests[i][j];
        }
        cout << " -> " << singleNumberII(tests[i]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
