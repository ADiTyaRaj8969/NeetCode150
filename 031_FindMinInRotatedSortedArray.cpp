// Topic: Find Minimum in Rotated Sorted Array
// Description: Return smallest element in rotated sorted array without duplicates.
// Approach: Binary search using mid vs right to decide which half contains minimum.

#include <bits/stdc++.h>
using namespace std;

int findMin(const vector<int>& nums)
{
    int l = 0, r = (int)nums.size() - 1;
    while (l < r)
    {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] > nums[r])
            l = mid + 1;
        else
            r = mid;
    }
    return nums[l];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{3, 4, 5, 1, 2}, {4, 5, 6, 7, 0, 1, 2}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": -> " << findMin(tests[i]) << "\n";
    }
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
