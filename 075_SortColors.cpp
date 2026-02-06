// Topic: Sort Colors (Dutch National Flag)
// Description: Given an array with values 0,1,2 representing colors, sort in-place so that same
// colors are adjacent in order 0,1,2. Approach: Three-way partitioning (low, mid, high pointers).
// Single pass O(n), O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums)
{
    int low = 0, mid = 0, high = (int)nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
            swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1)
            ++mid;
        else
            swap(nums[mid], nums[high--]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {2, 0, 2, 1, 1, 0};
    sortColors(a);
    for (size_t i = 0; i < a.size(); ++i) cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
