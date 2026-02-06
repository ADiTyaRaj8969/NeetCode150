// Topic: Palindrome Partitioning
// Description: Split string into all possible palindrome partitions.
// Approach: Backtracking with palindrome check (expand or DP precompute). We'll use on-the-fly
// check with memoization.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<vector<string>> partition(const string& s)
    {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> cur;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<bool(int, int)> isPal = [&](int l, int r)
        {
            if (l >= r)
                return true;
            if (memo[l][r] != -1)
                return memo[l][r];
            return memo[l][r] = (s[l] == s[r]) && isPal(l + 1, r - 1);
        };
        function<void(int)> dfs = [&](int idx)
        {
            if (idx == n)
            {
                res.push_back(cur);
                return;
            }
            for (int j = idx; j < n; ++j)
            {
                if (isPal(idx, j))
                {
                    cur.push_back(s.substr(idx, j - idx + 1));
                    dfs(j + 1);
                    cur.pop_back();
                }
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
    vector<string> tests = {"aab", "a"};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": \"" << tests[i] << "\" -> \n";
        auto res = Solution().partition(tests[i]);
        for (auto& v : res)
        {
            for (int j = 0; j < (int)v.size(); ++j)
            {
                if (j)
                    cout << " ";
                cout << v[j];
            }
            cout << "\n";
        }
    }
}

/*
Time Complexity: Exponential in worst case (number of partitions)
Space Complexity: O(n) recursion depth + output
*/
