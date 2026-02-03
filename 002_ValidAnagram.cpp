// Topic: Valid Anagram
// Description: Determine if two strings have identical character frequencies.
// Approach: Count characters using fixed-size array (assuming ASCII lowercase) or unordered_map for
// general case.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool isAnagram(const string& s, const string& t)
    {
        if (s.size() != t.size())
            return false;
        array<int, 26> cnt{};
        for (size_t i = 0; i < s.size(); ++i)
        {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        for (int x : cnt)
            if (x)
                return false;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<string, string>> tests = {{"anagram", "nagaram"}, {"rat", "car"}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto& p = tests[i];
        cout << "Test " << (i + 1) << ": (" << p.first << "," << p.second << ") -> "
             << (Solution().isAnagram(p.first, p.second) ? "true" : "false") << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1) (26-size array)
*/
