// Topic: House Robber
// Description: Given an array of non-negative integers representing money at each house, determine
// the maximum amount that can be robbed without robbing adjacent houses. Approach: Dynamic
// programming with two variables (prev and curr). O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums)
{
    int prev = 0, curr = 0;
    for (int x : nums)
    {
        int next = max(curr, prev + x);
        prev = curr;
        curr = next;
    }
    return curr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 2, 3, 1}, {2, 7, 9, 3, 1}, {0}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << rob(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
