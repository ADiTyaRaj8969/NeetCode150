// Topic: Search in Rotated Sorted Array
// Description: Search element's index in rotated sorted array without duplicates.
// Approach: Modified binary search deciding which half is sorted.

#include <bits/stdc++.h>
using namespace std;

int searchRotated(const vector<int>& nums, int target)
{
    int l = 0, r = (int)nums.size() - 1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target)
            return mid;
        if (nums[l] <= nums[mid])
        {
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1: target=0 -> " << searchRotated(a, 0) << "\n";
    cout << "Test 2: target=3 -> " << searchRotated(a, 3) << "\n";
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
