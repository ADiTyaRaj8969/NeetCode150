// Topic: Generate Parentheses
// Description: Generate all valid combinations of n pairs of parentheses.
// Approach: Backtracking keeping counts of open/close used.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string cur;
        cur.reserve(2 * n);
        function<void(int, int)> dfs = [&](int open, int close)
        {
            if ((int)cur.size() == 2 * n)
            {
                res.push_back(cur);
                return;
            }
            if (open < n)
            {
                cur.push_back('(');
                dfs(open + 1, close);
                cur.pop_back();
            }
            if (close < open)
            {
                cur.push_back(')');
                dfs(open, close + 1);
                cur.pop_back();
            }
        };
        dfs(0, 0);
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> tests = {3, 1};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto ans = Solution().generateParenthesis(tests[i]);
        cout << "Test " << (i + 1) << ": n=" << tests[i] << " -> ";
        for (size_t j = 0; j < ans.size(); ++j)
        {
            if (j)
                cout << ", ";
            cout << ans[j];
        }
        cout << "\n";
    }
}

/*
Time Complexity: Catalan number ~ O(4^n / sqrt(n)) outputs; generating each is proportional to
output size. Space Complexity: O(n) recursion depth plus output storage
*/
