// Topic: Remove Duplicates from Sorted Array II
// Description: Given a sorted array, remove duplicates in-place such that duplicates are allowed at
// most twice. Approach: Two pointers. Maintain a write index and allow up to two copies.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int j = 2;  // next write position
    for (int i = 2; i < n; ++i)
    {
        if (nums[i] != nums[j - 2])
            nums[j++] = nums[i];
    }
    return j;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{1, 1, 1, 2, 2, 3}, {0, 0, 1, 1, 1, 2}, {1, 2, 3}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto a = tests[i];
        int len = removeDuplicates(a);
        cout << "Test " << (i + 1) << ": len=" << len << " -> ";
        for (int j = 0; j < len; ++j) cout << a[j] << (j + 1 == len ? '\n' : ' ');
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
