// Topic: Word Break
// Description: Given a string s and a dictionary of words, determine if s can be segmented into a
// sequence of dictionary words. Approach: DP where dp[i] = true if s[0..i) can be segmented.

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(const string& s, const vector<string>& wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<char> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (dp[j] && dict.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
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
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": s=\"" << tests[i].first << "\" dict={";
        for (size_t j = 0; j < tests[i].second.size(); ++j)
        {
            if (j)
                cout << ",";
            cout << tests[i].second[j];
        }
        cout << "} -> " << (wordBreak(tests[i].first, tests[i].second) ? "True" : "False") << "\n";
    }
}

/*
Time Complexity: O(n^2 * k) where k is average substring creation cost, can be optimized with trie.
Space Complexity: O(n + dict)
*/
