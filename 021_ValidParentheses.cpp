// Topic: Valid Parentheses
// Description: Determine if parentheses sequence is properly nested.
// Approach: Use a stack to match closing to last opening bracket.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    bool isValid(const string& s)
    {
        string st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push_back(c);
            else
            {
                if (st.empty())
                    return false;
                char t = st.back();
                st.pop_back();
                if ((c == ')' && t != '(') || (c == ']' && t != '[') || (c == '}' && t != '{'))
                    return false;
            }
        }
        return st.empty();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> tests = {"()", "()[]{}", "(]"};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": \"" << tests[i] << "\" -> "
             << (Solution().isValid(tests[i]) ? "true" : "false") << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
