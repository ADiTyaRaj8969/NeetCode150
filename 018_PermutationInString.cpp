// Topic: Permutation in String
// Description: Check if one string's permutation exists within another.
// Approach: Sliding window with char counts, compare frequency arrays.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool checkInclusion(const string& s1, const string& s2)
    {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;
        array<int, 26> need{};
        for (char c : s1) ++need[c - 'a'];
        array<int, 26> window{};
        for (int i = 0; i < n; ++i)
        {
            ++window[s2[i] - 'a'];
            if (i >= m)
                --window[s2[i - m] - 'a'];
            if (window == need)
                return true;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<string, string>> tests = {{"ab", "eidbaooo"}, {"ab", "eidboaoo"}, {"adc", "dcda"}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": s1=\"" << tests[i].first << "\", s2=\"" << tests[i].second
             << "\" -> "
             << (Solution().checkInclusion(tests[i].first, tests[i].second) ? "true" : "false")
             << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
