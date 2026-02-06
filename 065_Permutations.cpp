// Topic: Permutations
// Description: Return all possible orderings of elements.
// Approach: Backtracking swapping or using used array. We'll use in-place swapping.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        function<void(int)> dfs = [&](int i)
        {
            if (i == (int)nums.size())
            {
                res.push_back(nums);
                return;
            }
            for (int j = i; j < (int)nums.size(); ++j)
            {
                swap(nums[i], nums[j]);
                dfs(i + 1);
                swap(nums[i], nums[j]);
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
    auto res = Solution().permute(a);
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
Time Complexity: O(n! * n) to generate all permutations
Space Complexity: O(n) recursion depth + output
*/
