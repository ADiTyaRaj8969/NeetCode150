// Topic: Longest Repeating Character Replacement
// Description: Maximize substring length after at most k replacements.
// Approach: Sliding window keeping counts and max frequency in window.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int characterReplacement(const string& s, int k)
    {
        vector<int> cnt(26, 0);
        int maxf = 0, left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right)
        {
            maxf = max(maxf, ++cnt[s[right] - 'A']);
            while (right - left + 1 - maxf > k)
            {
                --cnt[s[left] - 'A'];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<string, int>> tests = {{"ABAB", 2}, {"AABABBA", 1}, {"AAAA", 2}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": \"" << tests[i].first << "\", k=" << tests[i].second
             << " -> " << Solution().characterReplacement(tests[i].first, tests[i].second) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
