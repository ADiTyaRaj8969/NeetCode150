// Topic: Longest Consecutive Sequence
// Description: Find length of the longest consecutive number sequence in an array.
// Approach: Use unordered_set to expand sequences starting from numbers that are sequence starts.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int longestConsecutive(const vector<int>& nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : nums)
        {
            if (s.find(x - 1) == s.end())
            {
                int cur = 1;
                while (s.find(x + cur) != s.end()) ++cur;
                best = max(best, cur);
            }
        }
        return best;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{100, 4, 200, 1, 3, 2}, {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        for (size_t i = 0; i < tests[t].size(); ++i)
        {
            if (i)
                cout << ",";
            cout << tests[t][i];
        }
        cout << " -> " << Solution().longestConsecutive(tests[t]) << "\n";
    }
}

/*
Time Complexity: O(n) average
Space Complexity: O(n)
*/
