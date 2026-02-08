// Topic: Word Break
// Description: Given a string s and a dictionary of words, determine if s can be segmented into a
// space-separated sequence of dictionary words. Approach: DP where dp[i] indicates s[0..i) can be
// segmented.

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(const string& s, const vector<string>& wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dp[j] && dict.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, vector<string>>> tests = {
        {"leetcode", {"leet", "code"}},
        {"applepenapple", {"apple", "pen"}},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << (wordBreak(tests[i].first, tests[i].second) ? 1 : 0)
             << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n^2 * L) where L average substring cost (can be optimized)
Space Complexity: O(n + total dict size)
*/
