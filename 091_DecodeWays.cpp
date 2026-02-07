// Topic: Decode Ways
// Description: Given a string of digits, count how many ways it can be decoded (1->A, 2->B, ...,
// 26->Z). Approach: DP - ways[i] = number ways to decode suffix starting at i; compute iteratively
// from end.

#include <bits/stdc++.h>
using namespace std;

int numDecodings(const string& s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    vector<int> dp(n + 1, 0);
    dp[n] = 1;  // empty string
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i + 1];
        if (i + 1 < n)
        {
            int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (val >= 10 && val <= 26)
                dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tests = {"12", "226", "0"};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << numDecodings(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) (can be reduced to O(1))
*/
