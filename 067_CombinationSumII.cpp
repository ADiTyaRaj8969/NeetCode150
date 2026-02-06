// Topic: Combination Sum II
// Description: Return unique combinations summing to target where each number may be used once.
// Approach: Sort candidates and backtrack, skipping duplicates at the same recursion level.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
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
            for (int i = idx; i < (int)candidates.size(); ++i)
            {
                if (i > idx && candidates[i] == candidates[i - 1])
                    continue;
                if (candidates[i] > remaining)
                    break;
                cur.push_back(candidates[i]);
                dfs(i + 1, remaining - candidates[i]);
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
    vector<int> a = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto res = Solution().combinationSum2(a, target);
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
Time Complexity: Exponential in worst case (depends on branching)
Space Complexity: O(n) recursion depth + output
*/
