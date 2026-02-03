// Topic: Two Sum
// Description: Find two indices whose elements sum up to a target value.
// Approach: Single-pass hashmap to store seen numbers and their indices.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<int> twoSum(const vector<int>& nums, int target)
    {
        unordered_map<int, int> mp;
        mp.reserve(nums.size() * 2);
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int need = target - nums[i];
            auto it = mp.find(need);
            if (it != mp.end())
                return {it->second, i};
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<vector<int>, int>> tests = {{{2, 7, 11, 15}, 9}, {{3, 2, 4}, 6}, {{3, 3}, 6}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto& t = tests[i];
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < t.first.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << t.first[j];
        }
        cout << " target=" << t.second << " -> ";
        auto res = Solution().twoSum(t.first, t.second);
        if (res.empty())
            cout << "No solution\n";
        else
            cout << res[0] << "," << res[1] << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
