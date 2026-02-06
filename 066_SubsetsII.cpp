// Topic: Subsets II
// Description: Generate unique subsets avoiding duplicates.
// Approach: Sort input and backtrack skipping duplicates at the same recursion level.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> dfs = [&](int idx)
        {
            res.push_back(cur);
            for (int i = idx; i < (int)nums.size(); ++i)
            {
                if (i > idx && nums[i] == nums[i - 1])
                    continue;
                cur.push_back(nums[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {1, 2, 2};
    auto res = Solution().subsetsWithDup(a);
    for (auto& v : res)
    {
        for (int i = 0; i < (int)v.size(); ++i)
        {
            if (i)
                cout << " ";
            cout << v[i];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n * 2^n) worst-case (output size)
Space Complexity: O(n) recursion depth + output
*/
