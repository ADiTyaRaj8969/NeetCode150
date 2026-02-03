// Topic: Contains Duplicate
// Description: Check if any number appears more than once in the array.
// Approach: Use a hash set to detect duplicates in O(n) average time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool containsDuplicate(const vector<int>& nums)
    {
        unordered_set<int> seen;
        seen.reserve(nums.size() * 2);
        for (int x : nums)
        {
            if (!seen.insert(x).second)
                return true;  // already present
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Embedded tests
    vector<vector<int>> tests = {{1, 2, 3, 1}, {1, 2, 3}, {}};
    Solution sol;
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < tests[i].size(); ++j)
        {
            if (j)
                cout << ",";
            cout << tests[i][j];
        }
        cout << " -> " << (sol.containsDuplicate(tests[i]) ? "true" : "false") << "\n";
    }
    return 0;
}

/*
Time Complexity: O(n) on average, where n is the number of elements (unordered_set insert / find
average O(1)). Space Complexity: O(n) extra space for the unordered_set storing seen elements.
*/
