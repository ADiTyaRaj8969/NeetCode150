// Topic: Kth Largest Element in an Array
// Description: Find kth largest element using selection algorithm.
// Approach: Use nth_element (introselect) for average O(n) time and O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + (n - k), nums.end());
    return nums[n - k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {3, 2, 1, 5, 6, 4};
    cout << "Test 1 -> " << findKthLargest(a, 2) << "\n";  // expect 5
    vector<int> b = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << "Test 2 -> " << findKthLargest(b, 4) << "\n";  // expect 4
}

/*
Time Complexity: O(n) average
Space Complexity: O(1)
*/
