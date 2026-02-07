// Topic: Merge Sorted Array
// Description: Merge two sorted arrays where the first has enough space at the end to hold the
// second. Modify nums1 in-place. Approach: Merge from the end using three pointers.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<vector<int>, vector<int>>> tests = {
        {{1, 2, 3}, {2, 5, 6}}, {{0}, {1}}, {{1, 4, 7}, {2, 3, 6}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto a = tests[i].first;
        auto b = tests[i].second;
        int m = (int)a.size(), n = (int)b.size();
        vector<int> nums1(m + n);
        for (int k = 0; k < m; ++k) nums1[k] = a[k];
        for (int k = m; k < m + n; ++k) nums1[k] = 0;
        merge(nums1, m, b, n);
        cout << "Test " << (i + 1) << ": ";
        for (int j = 0; j < m + n; ++j) cout << nums1[j] << (j + 1 == m + n ? '\n' : ' ');
    }
    return 0;
}

/*
Time Complexity: O(m+n)
Space Complexity: O(1)
*/
