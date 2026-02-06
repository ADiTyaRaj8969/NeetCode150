// Topic: Subsets
// Description: Generate all possible subsets of a list.
// Approach: Backtracking or iterative bitmask. We'll use backtracking.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> dfs = [&](int idx)
        {
            res.push_back(cur);
            for (int i = idx; i < (int)nums.size(); ++i)
            {
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
    vector<int> a = {1, 2, 3};
    auto res = Solution().subsets(a);
    for (auto& s : res)
    {
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (i)
                cout << " ";
            cout << s[i];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n * 2^n) total output size
Space Complexity: O(n) recursion depth + output
*/
