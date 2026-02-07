// Topic: Search Insert Position
// Description: Given a sorted array and a target, return the index if the target is found.
// If not, return the index where it would be inserted in order.
// Approach: Binary search (lower_bound). O(log n) time.

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int l = 0, r = (int)nums.size();
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, int>> tests = {
        {{1, 3, 5, 6}, 5},  // expect 2
        {{1, 3, 5, 6}, 2},  // expect 1
        {{1, 3, 5, 6}, 7}   // expect 4
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto nums = tests[i].first;
        int target = tests[i].second;
        cout << "Test " << (i + 1) << ": " << searchInsert(nums, target) << '\n';
    }

    return 0;
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
