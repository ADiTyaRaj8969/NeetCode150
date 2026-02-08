// Topic: Word Break II
// Description: Given a string s and a dictionary, return all possible sentences where words are
// separated by spaces. Approach: DFS with memoization (backtracking + DP) to avoid recomputation.

#include <bits/stdc++.h>
using namespace std;

vector<string> wordBreakHelper(const string& s, const unordered_set<string>& dict,
                               unordered_map<int, vector<string>>& memo, int start)
{
    if (memo.count(start))
        return memo[start];
    vector<string> res;
    if (start == s.size())
    {
        res.push_back("");
        memo[start] = res;
        return res;
    }
    for (int end = start + 1; end <= s.size(); ++end)
    {
        string w = s.substr(start, end - start);
        if (dict.count(w))
        {
            auto tails = wordBreakHelper(s, dict, memo, end);
            for (auto& t : tails)
            {
                string sentence = w + (t.empty() ? "" : " " + t);
                res.push_back(sentence);
            }
        }
    }
    memo[start] = res;
    return res;
}

vector<string> wordBreakII(const string& s, const vector<string>& wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> memo;
    return wordBreakHelper(s, dict, memo, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<string, vector<string>>> tests = {
        {"catsanddog", {"cat", "cats", "and", "sand", "dog"}},
        {"pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"}}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": s=\"" << tests[i].first << "\"\n";
        auto ans = wordBreakII(tests[i].first, tests[i].second);
        cout << "Count=" << ans.size() << "\n";
        for (auto& line : ans) cout << line << "\n";
        cout << "\n";
    }
}

/*
Time Complexity: Exponential in worst-case but memoization prunes; depends on number of valid
segmentations. Space Complexity: O(n * average sentence length + memo)
*/
