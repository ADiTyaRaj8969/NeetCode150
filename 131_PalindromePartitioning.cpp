// Topic: Palindrome Partitioning
// Description: Given a string s, partition s such that every substring of the partition is a
// palindrome. Return all possible palindrome partitioning of s. Approach: Backtracking with O(n *
// 2^n) worst-case for generating partitions; check palindrome in O(n) but we optimize by checking
// on the fly.

#include <bits/stdc++.h>
using namespace std;

bool isPal(const string& s, int l, int r)
{
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}

void dfs(const string& s, int idx, vector<string>& cur, vector<vector<string>>& res)
{
    int n = s.size();
    if (idx == n)
    {
        res.push_back(cur);
        return;
    }
    for (int j = idx; j < n; ++j)
    {
        if (isPal(s, idx, j))
        {
            cur.push_back(s.substr(idx, j - idx + 1));
            dfs(s, j + 1, cur, res);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> cur;
    dfs(s, 0, cur, res);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tests = {"aab", "a", "racecar"};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        auto ans = partition(tests[i]);
        cout << "Test " << (i + 1) << " (s=\"" << tests[i] << "\"): count=" << ans.size() << '\n';
        for (auto& p : ans)
        {
            for (size_t j = 0; j < p.size(); ++j)
            {
                if (j)
                    cout << " ";
                cout << p[j];
            }
            cout << '\n';
        }
    }
    return 0;
}

/*
Time Complexity: Exponential in worst-case (output-sensitive). Checking palindrome costs O(n) but is
done inline. Space Complexity: O(n) recursion + output size
*/
