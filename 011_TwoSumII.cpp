// Topic: Two Sum II - Input array is sorted
// Description: Find two numbers in a sorted array that sum to a target.
// Approach: Two-pointer from both ends, O(n) time, O(1) space.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    pair<int, int> twoSum(vector<int>& numbers, int target)
    {
        int l = 0, r = (int)numbers.size() - 1;
        while (l < r)
        {
            int s = numbers[l] + numbers[r];
            if (s == target)
                return {l + 1, r + 1};  // 1-based index usual in problem
            if (s < target)
                ++l;
            else
                --r;
        }
        return {-1, -1};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{2, 7, 11, 15}, 9}, {{2, 3, 4}, 6}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        auto& t = tests[i];
        for (size_t j = 0; j < t.first.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << t.first[j];
        }
        cout << " target=" << t.second << " -> ";
        auto p = Solution().twoSum(const_cast<vector<int>&>(t.first), t.second);
        cout << p.first << "," << p.second << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
