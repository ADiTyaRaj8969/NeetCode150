// Topic: Binary Search
// Description: Search target value in sorted array efficiently using divide-and-conquer.
// Approach: Standard iterative binary search returning index or -1.

#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& a, int target)
{
    int l = 0, r = (int)a.size() - 1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{-1, 0, 3, 5, 9, 12}, 9}, {{1, 2, 3, 4, 5}, 2}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": target=" << tests[i].second << " -> "
             << binarySearch(tests[i].first, tests[i].second) << "\n";
    }
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
