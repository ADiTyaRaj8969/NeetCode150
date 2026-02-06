// Topic: Combination Sum
// Description: Return combinations summing to target, reuse numbers allowed.
// Approach: Backtracking with candidates sorted to prune branches.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int idx, int remaining)
        {
            if (remaining == 0)
            {
                res.push_back(cur);
                return;
            }
            for (int i = idx; i < (int)candidates.size() && candidates[i] <= remaining; ++i)
            {
                cur.push_back(candidates[i]);
                dfs(i, remaining - candidates[i]);
                cur.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> cand = {2, 3, 6, 7};
    int target = 7;
    auto res = Solution().combinationSum(cand, target);
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
Time Complexity: Depends on branching; in worst-case exponential
Space Complexity: O(target / min(candidates)) recursion depth
*/
