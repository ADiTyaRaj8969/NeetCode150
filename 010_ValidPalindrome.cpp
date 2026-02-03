// Topic: Valid Palindrome
// Description: Check if a string reads the same backward ignoring punctuation and case.
// Approach: Two-pointer with char filtering and case normalization.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool isPalindrome(const string& s)
    {
        int i = 0, j = (int)s.size() - 1;
        while (i < j)
        {
            while (i < j && !isalnum((unsigned char)s[i])) ++i;
            while (i < j && !isalnum((unsigned char)s[j])) --j;
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> tests = {"A man, a plan, a canal: Panama", "race a car"};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": \"" << tests[i] << "\" -> "
             << (Solution().isPalindrome(tests[i]) ? "true" : "false") << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
