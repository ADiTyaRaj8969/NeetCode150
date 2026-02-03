// Topic: Longest Substring Without Repeating Characters
// Description: Find length of substring with all unique characters.
// Approach: Sliding window with last-seen indices array/map.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int lengthOfLongestSubstring(const string& s)
    {
        vector<int> last(256, -1);
        int start = 0, best = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            start = max(start, last[(unsigned char)s[i]] + 1);
            best = max(best, i - start + 1);
            last[(unsigned char)s[i]] = i;
        }
        return best;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> tests = {"abcabcbb", "bbbbb", "pwwkew"};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": \"" << tests[t] << "\" -> "
             << Solution().lengthOfLongestSubstring(tests[t]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1) (256-size table)
*/
