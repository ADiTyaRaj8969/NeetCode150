// Topic: Minimum Window Substring
// Description: Find smallest substring containing all characters of another string.
// Approach: Sliding window with frequency counts and expand/contract pointers.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    string minWindow(const string& s, const string& t)
    {
        if (t.empty() || s.empty())
            return "";
        array<int, 128> need{};
        for (char c : t) ++need[(unsigned char)c];
        int required = t.size();
        int l = 0, bestL = 0, bestLen = INT_MAX;
        for (int r = 0; r < (int)s.size(); ++r)
        {
            if (need[(unsigned char)s[r]] > 0)
                --required;
            --need[(unsigned char)s[r]];
            while (required == 0)
            {
                if (r - l + 1 < bestLen)
                {
                    bestLen = r - l + 1;
                    bestL = l;
                }
                ++need[(unsigned char)s[l]];
                if (need[(unsigned char)s[l]] > 0)
                    ++required;
                ++l;
            }
        }
        return bestLen == INT_MAX ? string() : s.substr(bestL, bestLen);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<string, string>> tests = {{"ADOBECODEBANC", "ABC"}, {"a", "a"}, {"a", "aa"}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": s=\"" << tests[i].first << "\", t=\"" << tests[i].second
             << "\" -> \"" << Solution().minWindow(tests[i].first, tests[i].second) << "\"\n";
    }
}

/*
Time Complexity: O(n + m)
Space Complexity: O(1) (128-char table)
*/
