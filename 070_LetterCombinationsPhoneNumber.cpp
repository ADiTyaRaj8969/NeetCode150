// Topic: Letter Combinations of a Phone Number
// Description: Map digits to letter combinations (telephone digits 2-9).
// Approach: Backtracking building combinations using mapping table.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<string> letterCombinations(const string& digits)
    {
        if (digits.empty())
            return {};
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string cur;
        cur.reserve(digits.size());
        function<void(int)> dfs = [&](int idx)
        {
            if (idx == (int)digits.size())
            {
                res.push_back(cur);
                return;
            }
            int d = digits[idx] - '0';
            for (char c : map[d])
            {
                cur.push_back(c);
                dfs(idx + 1);
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
    vector<string> tests = {"23", ""};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto res = Solution().letterCombinations(tests[i]);
        cout << "Test " << (i + 1) << " -> ";
        for (size_t j = 0; j < res.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << res[j];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(4^n * n) where n = number of digits (4 for digits with 4 letters)
Space Complexity: O(n) recursion depth + output
*/
